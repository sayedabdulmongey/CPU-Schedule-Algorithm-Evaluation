
/*
Algorithm Evaluation(Deterministic Evaluation)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// create struct of process
struct process
{
    string name;
    vector<int> arrival_time;
    int total_burst_time;
    int remaining_burst_time;
    vector<int> dispatich_time;

    bool operator<(const process &other) const
    {
        // Change the comparison based on the element you want to prioritize
        return remaining_burst_time > other.remaining_burst_time; // For example, ordering by priority in descending order
    }
};

// functions needed
int calculate_waiting_time(process p);
int calulate_responce_time(process p);
int calculate_turnaround_time(process p);
void take_process();
void print_result(int n);
void print_gantt_chart();
bool arrived(int click);
void update_disbatch_time(int click, string name);
void update_arrival_time(int click, string name);

// global variables needed
priority_queue<process> ready_queue;
vector<process> all_process;
vector<process> gantt_chart;
vector<string> finished;

int main()
{
    // take input from file
    int number_of_process;
    freopen("example.txt", "r", stdin);
    freopen("solution.txt", "w", stdout);
    cin >> number_of_process;
    for (int i = 0; i < number_of_process; i++)
    {
        take_process();
    }

    int click = 0;
    while (1)
    {
        // update remaining time
        if (!gantt_chart.empty())
        {
            gantt_chart[gantt_chart.size() - 1].remaining_burst_time--;
        }

        // check if any process finshed excution
        if (!gantt_chart.empty() && gantt_chart.back().remaining_burst_time == 0)
        {
            finished.push_back(gantt_chart.back().name);
            if (!ready_queue.empty())
            {
                gantt_chart.push_back(ready_queue.top());
                update_disbatch_time(click, ready_queue.top().name); // p --> excution --> vector [dispatch click]
                ready_queue.pop();
            }
        }

        // check if process arived
        if (arrived(click))
        {
            if (gantt_chart.empty())
            {
                gantt_chart.push_back(ready_queue.top());
                update_disbatch_time(click, ready_queue.top().name);
                ready_queue.pop();
            }
            else
            {
                if (gantt_chart.back().remaining_burst_time > ready_queue.top().remaining_burst_time)
                {
                    update_arrival_time(click, gantt_chart.back().name);
                    ready_queue.push(gantt_chart.back());
                    gantt_chart.push_back(ready_queue.top());
                    update_disbatch_time(click, ready_queue.top().name);
                    ready_queue.pop();
                }
            }
        }
        if (finished.size() == number_of_process)
            break;

        click++;
    }
    cout << "\t\t\t\t SRJF Algorithm" << endl;
    print_gantt_chart();
    print_result(number_of_process);

    return 0;
}

int calculate_waiting_time(process p)
{
    int waiting_time = 0;
    for (int i = 0; i < p.arrival_time.size(); i++)
    {
        waiting_time += (p.dispatich_time[i] - p.arrival_time[i]);
    }
    return waiting_time;
}
int calulate_responce_time(process p)
{
    return p.dispatich_time[0] - p.arrival_time[0];
}
int calculate_turnaround_time(process p)
{
    return calculate_waiting_time(p) + p.total_burst_time;
}

void take_process()
{
    process p;
    int arrival_time;
    cin >> p.name;
    cin >> p.total_burst_time;
    cin >> arrival_time;
    p.arrival_time.push_back(arrival_time);
    p.remaining_burst_time = p.total_burst_time;
    all_process.push_back(p);
}

void print_result(int n)
{
    float wt, trt, rt, total_wt = 0, total_rt = 0, total_trt = 0;
    cout << "\t\t\t\t Result Report" << endl;
    cout << "\t\t\t\tname\twt\ttrt\trt\n";
    for (int i = 0; i < n; i++)
    {
        wt = calculate_waiting_time(all_process[i]);
        trt = calculate_turnaround_time(all_process[i]);
        rt = calulate_responce_time(all_process[i]);
        cout << "\t\t\t\t" << all_process[i].name << "\t\t" << wt << "\t" << trt << "\t" << rt << "\n";
        total_wt += wt;
        total_trt += trt;
        total_rt += rt;
    }
    cout << "\t\t\t\t"
         << "AVG\t\t" << total_wt / n << "\t" << total_trt / n << "\t" << total_rt / n << "\n";
}
void print_gantt_chart()
{
    cout << "\t\t\t\t GanntChart" << endl;
    cout << "\t\t\t\t|";
    for (int i = 0; i < gantt_chart.size(); i++)
        cout << "--|";
    cout << endl
         << "\t\t\t\t|";
    for (int i = 0; i < gantt_chart.size(); i++)
    {
        cout << gantt_chart[i].name << "|";
    }
    cout << endl
         << "\t\t\t\t|";
    for (int i = 0; i < gantt_chart.size(); i++)
        cout << "--|";
    cout << endl
         << endl
         << endl;
}
bool arrived(int click)
{
    bool flag = 0;
    for (int i = 0; i < all_process.size(); i++)
    {
        if (all_process[i].arrival_time[0] == click)
        {
            ready_queue.push(all_process[i]);
            flag = 1;
        }
    }
    return flag;
}

void update_disbatch_time(int click, string name)
{
    for (int i = 0; i < all_process.size(); i++)
    {
        if (all_process[i].name == name)
        {
            all_process[i].dispatich_time.push_back(click);
        }
    }
}
void update_arrival_time(int click, string name)
{
    for (int i = 0; i < all_process.size(); i++)
    {
        if (all_process[i].name == name)
        {
            all_process[i].arrival_time.push_back(click);
        }
    }
}
