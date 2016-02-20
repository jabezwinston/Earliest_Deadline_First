/*
 * func_def.c
 *
 *  Created on: 27-Jan-2016
 *      Author: winston
 */
#include<stdio.h>
#include"edf.h"

void get_tasks(task *t1,int n)
{
	int i=0;
	while(i<n)
	{
	printf("Enter Task %d parameters\n",i+1);
	printf("Arrival time: ");
	scanf("%d",&t1->T[arrival]);
	printf("Execution time: ");
	scanf("%d",&t1->T[execution]);
	printf("Deadline time: ");
	scanf("%d",&t1->T[deadline]);
	printf("Period: ");
	scanf("%d",&t1->T[period]);
	t1->T[abs_arrival]=0;
	t1->T[execution_copy]=0;
	t1->T[abs_deadline]=0;
	t1->instance =0;
	t1->alive = 0;
	t1++;
	i++;
	}
}

int hyperperiod_calc(task *t1,int n)
{
	int i=0,ht,a[10];
	while(i<n)

		{
		a[i]=t1->T[period];
		t1++;
		i++;
		}
	ht=lcm(a,n);

	return ht;
}

int gcd(int a, int b)
{
  if (b == 0)
	  return a;
  else
  return gcd(b, a%b);
}

int lcm(int *a, int n)
{
  int res = 1, i;
  for (i = 0; i < n; i++)
  {
    res = res*a[i]/gcd(res, a[i]);
  }
  return res;
}



int sp_interrupt(task *t1,int tmr,int n)
{
int i=0,n1=0,a=0;
task *t1_copy;
t1_copy=t1;
	while(i<n)
	{
		if(tmr == t1->T[abs_arrival])
			{
			t1->alive = 1;
			a++;
			}
		t1++;
		i++;
	}

	t1 =t1_copy;
	i=0;

	while(i<n)
	{
		if(t1->alive==0)
			n1++;
			t1++;
			i++;
	}

	if(n1==n || a!=0)
	{
		return 1;
	}

	return 0;
}

void update_abs_deadline(task *t1,int n,int all)
{
int i=0;
		if(all)
		{
			while(i<n)
			{
				t1->T[abs_deadline] = t1->T[deadline] + t1->T[abs_arrival];
				t1++;
				i++;
			}
		}
		else
		{
		t1+=n;
		t1->T[abs_deadline] = t1->T[deadline] + t1->T[abs_arrival];
		}

}

void update_abs_arrival(task *t1,int n,int k,int all)
{
int i=0;
		if(all)
		{
			while(i<n)
			{
				t1->T[abs_arrival] = t1->T[arrival] + k*(t1->T[period]);
				t1++;
				i++;
			}
		}
		else
		{
		t1+=n;
		t1->T[abs_arrival] = t1->T[arrival] + k* (t1->T[period]);
		}

}

void copy_execution_time(task *t1,int n,int all)
{
	int i=0;
	if(all)
	{
		while(i<n)
		{
			t1->T[execution_copy] = t1->T[execution];
			t1++;
			i++;
		}
	}
	else
	{
		t1+=n;
		t1->T[execution_copy] = t1->T[execution];
	}
}


int min(task *t1,int n,int p)
{
	int i=0,min=0x7FFF,task_id=IDLE_TASK_ID;
	while(i<n)
	{
		if(min>t1->T[p] && t1->alive==1)
		{
			min=t1->T[p];
			task_id=i;
		}
		t1++;
		i++;
	}
	return task_id;
}


float cpu_util(task *t1,int n)
{
	int i=0;
	float cu=0;
	while(i<n)
	{
		cu = cu + (float)t1->T[execution]/(float)t1->T[deadline];
		t1++;
		i++;
	}
	return cu;

}

