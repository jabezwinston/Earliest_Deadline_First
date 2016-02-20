#define arrival			0
#define execution 		1
#define deadline		2
#define period			3
#define abs_arrival		4
#define execution_copy  5
#define abs_deadline	6

//stucture of a task
typedef struct
{
	int T[7],instance,alive;
/*
		These task parameters are given by the user
		T[0] == T[arrival]  			(Arrival time)
		T[1] == T[execution]			(Execution time)
		T[2] == T[deadline] 			(Deadline time)
		T[3] == T[period]  			    (Period)
	
		These task parameters are internal to the program
		T[4] == T[abs_arrival]  		(Absolute Arrival time)
		T[5] == T[execution_copy]	(Execution time copy)
		T[6] == T[abs_deadline]  	(Absolute Arrival time)

		instance (Number of times the tasks had arrived since time = 0)
		alive (Whether the task is ready? 0 for NOT READY and 1 for READY )
*/
}task;

#define IDLE_TASK_ID 1023   // Just a number I assigned
#define ALL 1
#define CURRENT 0

void get_tasks(task *t1,int n);				//Get tasks parameters - Arrival time , Execution time , Deasdline and Period
int hyperperiod_calc(task *t1,int n);			//Calculate hyperiod period of the task set  
float cpu_util(task *t1,int n);				//Calculates CPU utilization
int gcd(int a, int b);					//Find greatest common divisor
int lcm(int *a, int n);					//Find Least common multiple
int sp_interrupt(task *t1,int tmr,int n);		//Scheduling point interrupt
int min(task *t1,int n,int p);				//Find minimum of given task parameter
void update_abs_arrival(task *t1,int n,int k,int all);	//Update absolute arrival time (absolute arrival time = arrivaltime + instance*period) 
void update_abs_deadline(task *t1,int n,int all);	//Update absolute deadline (absolute deadline = absolute arrival time + deadline )
void copy_execution_time(task *t1,int n,int all);	//Keep a backup copy of execution time

