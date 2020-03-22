# Earliest Deadline First

Wrote a very simple EDF scheduler as a part of RTOS curriculum. It is recommended to compile the program with GCC. The old Turbo C too will work :stuck_out_tongue_closed_eyes:
Hope you like it. :smile:

Use the following command to compile in GCC.

```
$ gcc main.c func_def.c  -o EDF
```

### Sample

| Tasks | Arrival	| Execution  |  Deadline | Period |  
|:-----:|:---------:|:----------:|:---------:|:-------:
|T1	    |   1		|	  3 	 |	6        |   9    |
|T2	    |   3		|	  2 	 |	5        |   12   |
|T3	    |   4		|	  4 	 |	10       |   16   |



### How the program looks like
```bash
winston@winston-VirtualBox:~/EDF_Scheduler$ ./EDF
Enter number of tasks
3
Enter Task 1 parameters
Arrival time: 1
Execution time: 3
Deadline time: 6
Period: 8
Enter Task 2 parameters
Arrival time: 3
Execution time: 2
Deadline time: 5
Period: 12
Enter Task 3 parameters
Arrival time: 4
Execution time: 4
Deadline time: 10
Period: 16
CPU Utilization 0.791667
Tasks can be scheduled
0  Idle
1  Task 1
2  Task 1
3  Task 1
4  Task 2
5  Task 2
6  Task 3
7  Task 3
8  Task 3
9  Task 3
10  Task 1
11  Task 1
12  Task 1
13  Idle
14  Idle
15  Task 2
16  Task 2
17  Task 1
18  Task 1
19  Task 1
20  Task 3
21  Task 3
22  Task 3
23  Task 3
24  Idle
25  Task 1
26  Task 1
27  Task 1
28  Task 2
29  Task 2
30  Idle
31  Idle
32  Idle
33  Task 1
34  Task 1
35  Task 1
36  Task 3
37  Task 3
38  Task 3
39  Task 2
40  Task 2
41  Task 3
42  Task 1
43  Task 1
44  Task 1
45  Idle
46  Idle
47  Idle
48  Idle
```
