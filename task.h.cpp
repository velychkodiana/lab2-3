#pragma once
#include <string>
#include <vector>
struct Task
{
 std::string description;
 bool done;
}
void saveTasksToFile(const std::vector<task>Task>& tasks, const std::string& fileName);
std::vectjr<Task> loadTasksFromFile(const std:string& fileName);
