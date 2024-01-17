#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Job
{
    int deadline;
    int processingTime;

    Job(int d, int p) : deadline(d), processingTime(p) {}
};
// Compare the jobs in decreasing order
bool compare(const Job &a, const Job &b)
{
    return a.deadline > b.deadline;
}
void scheduleJobs(vector<Job> &jobs)
{
    // here sort them base on there deadlines in decreasing order
    sort(jobs.begin(), jobs.end(), compare);

    // here we track of time slots
    int Slots[jobs.size()] = {0}; //(slots= time slots)

    // SCHEDULE JOBS
    int comp_job = 0;
    for (int i = 0; i < jobs.size(); ++i)
    {
        for (int j = min(jobs[i].deadline - 1, static_cast<int>(jobs.size()) - 1); j >= 0; --j)
        {
            if (Slots[j] == 0)
            {

                Slots[j] = 1;
                comp_job++;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 0; i < jobs.size(); ++i)
    {
        if (Slots[i] == 1)
        {
            cout << "Job " << i + 1 << " ";
        }
    }
    cout << endl;
    cout << "Total Jobs Completed: " << comp_job << endl;
}

int main()
{
    // example
    vector<Job> jobs = {{1, 2}, {2, 1}, {3, 3}};
    scheduleJobs(jobs);
    return 0;
}