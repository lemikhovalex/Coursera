#include <iostream>
#include "string"
#include "map"

using namespace std;
/*
// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;
*/
class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return person_tasks.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person){
        person_tasks[person][TaskStatus::NEW]++;
    }

    void dumb_func_for_correct_output(TasksInfo& maps){
        for(auto it=maps.begin();it!=maps.end();){
            if(it->second == 0){
                it=maps.erase(it);
            }else{
                it++;
            }
        }
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count){

        TasksInfo out_new;
        TasksInfo out_old = person_tasks[person];
        if (task_count <= person_tasks[person][TaskStatus::NEW]){
            out_old[TaskStatus::NEW] -= task_count;
            out_new[TaskStatus::IN_PROGRESS] = task_count;
        } else{
            out_old[TaskStatus::NEW] = 0;
            out_new[TaskStatus::IN_PROGRESS] = person_tasks[person][TaskStatus::NEW];
            task_count -= person_tasks[person][TaskStatus::NEW];
            if(task_count <= person_tasks[person][TaskStatus::IN_PROGRESS]){
                out_old[TaskStatus::IN_PROGRESS] -= task_count;
                out_new[TaskStatus::TESTING] = task_count;
            } else{
                out_old[TaskStatus::IN_PROGRESS] = 0;
                out_new[TaskStatus::TESTING] = person_tasks[person][TaskStatus::IN_PROGRESS];
                task_count -= person_tasks[person][TaskStatus::IN_PROGRESS];
                if(task_count <= person_tasks[person][TaskStatus::TESTING]){
                    out_old[TaskStatus::TESTING] -= task_count;
                    out_new[TaskStatus::DONE] = task_count;
                } else{
                    out_old[TaskStatus::TESTING] = 0;
                    out_new[TaskStatus::DONE] = person_tasks[person][TaskStatus::TESTING];
                }
            }
        }
        person_tasks[person][TaskStatus::NEW] = out_new[TaskStatus::NEW] + out_old[TaskStatus::NEW];
        person_tasks[person][TaskStatus::IN_PROGRESS] = out_new[TaskStatus::IN_PROGRESS] + out_old[TaskStatus::IN_PROGRESS];
        person_tasks[person][TaskStatus::TESTING] = out_new[TaskStatus::TESTING] + out_old[TaskStatus::TESTING];
        person_tasks[person][TaskStatus::DONE] = out_new[TaskStatus::DONE] + out_old[TaskStatus::DONE];
        // dunno why they dont print done
        out_old[TaskStatus::DONE] = 0;
        dumb_func_for_correct_output(out_new);
        dumb_func_for_correct_output(out_old);
        dumb_func_for_correct_output(person_tasks[person]);
        return make_tuple(out_new, out_old);
    }

private:
    map<string, TasksInfo> person_tasks;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lex");
    }
    cout << "Lex's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lex"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Lex", 5);
    cout << "Updated Lex's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Lex's tasks: ";
    PrintTasksInfo(untouched_tasks);
    cout << endl << endl;

    cout << "Lex's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lex"));
    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Lex", 5);
    cout << "Updated Lex's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Lex's tasks: ";
    PrintTasksInfo(untouched_tasks);
    cout << endl << endl;

    cout << "Lex's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lex"));
    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Lex", 1);
    cout << "Updated Lex's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Lex's tasks: ";
    PrintTasksInfo(untouched_tasks);
    cout << endl << endl;


    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lex");
    }
    cout << "Lex's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Lex"));
    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Lex", 2);
    cout << "Updated Lex's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Lex's tasks: ";
    PrintTasksInfo(untouched_tasks);
    cout << endl << endl;
    return 0;
}