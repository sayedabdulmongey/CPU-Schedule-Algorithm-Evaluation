#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct process
{
  string name;
  int burst_time;
  int arrival_time;
  int dispatch_time;
  int remaining_burst_time;

  bool operator>(const process &other) const
  {
    return burst_time > other.burst_time;
  }
};

int calculate_waiting_time(process p);

int calulate_responce_time(process p);

int calculate_turnaround_time(process p);

void take_process();

void print_result(int n);

void print_gantt_chart();

void arrived(int click);

void update_dispatch_time(int click, string name);

priority_queue<process, vector<process>, greater<>> ready_queue;
vector<process> all_process;
vector<process> gantt_chart;
vector<string> finished;

int main()
{
  freopen("example.txt", "r", stdin);
  freopen("solution.txt", "w", stdout);

  int number_of_process;
  cin >> number_of_process;
  for (int i = 0; i < number_of_process; i++)
  {
    take_process();
  }

  int click = 0;

  while (true)
  {
    arrived(click);

    if (gantt_chart.size() && gantt_chart.back().remaining_burst_time)
    {
      gantt_chart.back().remaining_burst_time--;
      if (gantt_chart.back().remaining_burst_time == 0)
      {
        finished.push_back(gantt_chart.back().name);
      }
    }

    if ((gantt_chart.empty() || (gantt_chart.size() && !gantt_chart.back().remaining_burst_time)) && ready_queue.size())
    {
      gantt_chart.push_back(ready_queue.top());
      update_dispatch_time(click, ready_queue.top().name);
      ready_queue.pop();
    }

    if (finished.size() == number_of_process)
      break;
    click++;
  }
  cout << "\t\t\t\t SJF Algorithm" << endl;
  print_gantt_chart();
  print_result(number_of_process);

  return 0;
}

int calculate_waiting_time(process p)
{
  return p.dispatch_time - p.arrival_time;
}

int calulate_responce_time(process p)
{
  return p.dispatch_time - p.arrival_time;
}

int calculate_turnaround_time(process p)
{
  return calculate_waiting_time(p) + p.burst_time;
}

void take_process()
{
  process p;
  cin >> p.name;
  cin >> p.burst_time;
  cin >> p.arrival_time;
  p.remaining_burst_time = p.burst_time;
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

void arrived(int click)
{
  for (int i = 0; i < all_process.size(); i++)
  {
    if (all_process[i].arrival_time == click)
    {
      all_process[i].arrival_time = click;
      ready_queue.push(all_process[i]);
    }
  }
}

void update_dispatch_time(int click, string name)
{
  for (int i = 0; i < all_process.size(); i++)
  {
    if (all_process[i].name == name)
    {
      all_process[i].dispatch_time = click;
    }
  }
}
