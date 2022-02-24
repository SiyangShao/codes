#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3, "Ofast", "inline")
typedef long long ll;
int C, P;

struct skill {
	string name;
	int level;
};

struct contributor {
	string name;
	int id;
	bool available = true;
	map<string, skill> skills;
};

struct project {
	string name;
	int id;
	ll days_taken, score, best_before, roles;
	vector<skill> requirements;
	vector<vector<contributor>> candidates;
};

struct job {
	project p;
	vector<contributor> assigned_people;
	// assigned_people wil need to follow the order of requirements
	ll endtime;
};

map<string, bool> availability;

vector<project> waitlist;
vector<contributor> contributors;

vector<job> completed_project;

ll current_time = 0;
ll points = 0;

ll calculatepoint(ll endtime, project p) {
	if (endtime > p.best_before) {
		return max(0ll, p.score - (endtime - p.best_before));
	} else
		return p.score;
}

auto highest_points_first = [](auto a, auto b) {
	// highest_points_first
	return calculatepoint(current_time + a.days_taken, a) >
		   calculatepoint(current_time + b.days_taken, b);
};

priority_queue<project, vector<project>, decltype(highest_points_first)>
	ready_queue(highest_points_first);

auto timeline = [](auto a, auto b) { return a.endtime < b.endtime; };
priority_queue<job, vector<job>, decltype(timeline)> running(timeline);
// running

bool inside(contributor p, vector<contributor> &can) {
	for (auto &ppl : can) {
		if (p.name == ppl.name)
			return true;
	}
	return false;
}

bool haveskill(contributor p, skill s) {
	if (p.skills.find(s.name) == p.skills.end())
		return false;
	if ((p.skills)[s.name].level >= s.level)
		return true;

	return false;
}
// add projects with requirements meet from waitlist into ready_queue
void add_project_to_readyqueue() {
	vector<project> newlist;
	for (auto &p : waitlist) {
		int i = 0;
		bool can = true;
		for (auto &s : p.requirements) {

			for (auto &ppl : contributors) {

				if (inside(ppl, p.candidates[i]))
					continue;

				if (haveskill(ppl, s)) {
					p.candidates[i].emplace_back(ppl);
				}
			}
			if (p.candidates[i].empty()) {
				can = false;
				break;
			}
			i++;
		}
		if (can)
			ready_queue.push(p);
		else
			newlist.push_back(p);
	}
	waitlist = newlist;
}

// schedule projct that form ready_queue to running or ready_qeueu to
// waiting_list at the end ready_queue must be empty

vector<contributor> assigned;
int recurcall = 0;
bool recur_sche(int i, project p) {
	if (i >= p.candidates.size())
		return true;

	recurcall++;
	if (recurcall > P)
		return false;
	for (auto &ppl : p.candidates[i]) {
		if (availability[ppl.name] == false)
			continue;

		assigned.push_back(ppl);
		availability[ppl.name] = false;
		if (recur_sche(i + 1, p))
			return true;
		assigned.pop_back();
		availability[ppl.name] = true;
	}
	return false;
}

void schedule_project() {

	while (!ready_queue.empty()) {

		project p = ready_queue.top();
		ready_queue.pop();

		// for(auto req: p.requirements){
		recurcall = 0;
		if (recur_sche(0, p)) {
			job j;
			j.p = p;
			j.assigned_people = assigned;
			j.endtime = current_time + p.days_taken;
			running.push(j);
			assigned.clear();
		} else {
			waitlist.emplace_back(p);
		}
	}
}

// terminate the earliset job and resolve the outcome.
// resolve levelup, update availability, update currenttime
// throw the job to completed job
// update points
// complete all the project finished at the same time
void end_job() {
	assert(!running.empty());
	if (running.empty())
		return;
	job j = running.top();
	vector<job> to_end;
	to_end.emplace_back(j);
	running.pop();
	while (!running.empty() && running.top().endtime == j.endtime) {
		to_end.emplace_back(running.top());
		running.pop();
	}
	for (auto &J : to_end) {
		points += calculatepoint(J.endtime, J.p);
		completed_project.emplace_back(J);
		auto cnt = 0ll;
		for (auto &CONTRIBUTER : J.assigned_people) {
			availability[CONTRIBUTER.name] = true;
			if (J.p.requirements[cnt].level >
				CONTRIBUTER.skills[J.p.requirements[cnt].name].level) {
				CONTRIBUTER.skills[J.p.requirements[cnt].name].level++;
			}
			// auto it =
			// find_if(CONTRIBUTER.skills.begin(),CONTRIBUTER.skills.end(),[&](auto&
			// s){
			//     return s.name == J.p.requirements[cnt].name;
			// });
			// if((*it).level < J.p.requirements[cnt].level){
			//     (*it).level++;
			// }
			cnt++;
		}
	}
	current_time = j.endtime;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("output_C.txt", "w", stdout);
	freopen("c_collaboration.in.txt", "r", stdin);
	cin >> C >> P;
	contributors.resize(C);
	for (auto &i : contributors) {
		cin >> i.name;
		availability[i.name] = true;
		auto skills_num = 0ll;
		cin >> skills_num;
		while (skills_num--) {
			string skill_name;
			int skill_level;
			cin >> skill_name >> skill_level;
			skill ski;
			ski.name = skill_name;
			ski.level = skill_level;
			i.skills[skill_name] = ski;
		}
	}
	waitlist.resize(P);
	for (auto &i : waitlist) {
		cin >> i.name >> i.days_taken >> i.score >> i.best_before >> i.roles;
		i.requirements.resize(i.roles);
		for (auto &j : i.requirements) {
			cin >> j.name >> j.level;
		}
		i.candidates.assign(i.roles, vector<contributor>());
	}

	ll current_time = 0;
	add_project_to_readyqueue();
	schedule_project();
	int i = 0;
	do {
		end_job();
		add_project_to_readyqueue();
		schedule_project();
		i++;
		if (i > 100)
			break;
	} while (!running.empty()); // O(Projects)

	cout << completed_project.size() << "\n";
	for (auto &j : completed_project) {
		cout << j.p.name << "\n";
		for (auto &ppl : j.assigned_people) {
			cout << ppl.name << " ";
		}
		cout << "\n";
	}

	fclose(stdout);
	fclose(stdin);
	return 0;
}