#include<stdio.h>
#include<unistd.h>
struct Queue{
	int process_id;
	int a_time;
	int b_time;
	int c_time;
	int kt;
}f[100], s[100], m[100];

int kl, kp=0, ml=0, kc=0;
int quantum;

void r_robin(){
	int t= m[0].a_time, mk=0, aa=0, j, ev;
	while(t!=120 && aa!=kc){
		for(j=0; j<=mk; j++){
			if(m[j].kt > quantum){
				t += quantum;
				m[j].kt -= quantum;
			}
			else if(m[j].kt <=quantum && m[j].kt !=0){
				t += m[j].kt;
				m[j].kt =0;
				m[j].c_time = t;
				aa++;
			}
			else;
		}
		int begin = mk+1;
		for(ev= begin; ev<kc; ev++){
			if(m[ev].a_time <= t){
				mk++;
			}
		}
	}	
}

void join(){
	int poi=0, bn= 0, less, ht;
	if( kp!=0  && ml!=0){
		while(poi<ml && bn<kp){
			if(f[bn].a_time == s[poi].a_time){
				m[kc] = f[bn];
				kc++;
				bn++;
				m[kc]= s[poi];
				kc++;
				poi++;
			}
			else if(f[bn].a_time < s[poi].a_time){
				m[kc]= f[bn];
				kc++;
				bn++;
			}
			else if(f[bn].a_time > s[poi].a_time){
				m[kc]= s[poi];
				kc++;
				poi++;
			}
			else;
		}
		if(kc != (kp+ml)){
			if(kp!=bn){
				while(bn!=kp){
					m[kc]= f[bn];
					kc++;
					bn++;
				}
			}
			else if(ml!=poi){
				while(poi!=ml){
					m[kc]= s[poi];
					kc++;
					poi++;
				}
			}
		}
	}
	else if(kp==0){
		while(poi!=ml){
			m[kc]= s[poi];
			kc++;
			poi++;
		}
	}
	else if(ml==0){
		while(bn!=kp){
			m[kc]= f[bn];
			kc++;
			bn++;
		}
	}
	else {
		printf("\n Jobs are not avilable available\n");
	}
}

void display(){
	int j=0, total_time=0, add=0; 
	double average;
	printf("\n\n\nResult of the Execution of Process\n");
	printf("\nQuery ID\tArrival Time\tBust Time\tCompletion Time\tTurn Around Time\tWaiting Time");
	for(j; j<kc; j++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",
		m[j].process_id, (m[j].a_time+1000), m[j].b_time, (m[j].c_time+1000), (m[j].c_time-m[j].a_time), ((m[j].c_time-m[j].a_time)- m[j].b_time));
		total_time= m[j].c_time;
		add+= (m[j].c_time-m[j].a_time);
	}
	average = add/kc;
	printf("\n\nTotal time Spent for handling the queries: %d", total_time);
	printf("\nAverage query time: %lf", average);
	printf("\nAll the Process are successfully completed");
}

void get(){
	int ay,  j, t;
	printf("Enter total number of queries: "); 
	scanf("%d", &kl);
	if(kl==0) { printf("\n Queries are not found\n"); }
	else{
		printf("\nEnter Time Quantum for each Process: "); 
		scanf("%d", &quantum);
		for(j=0; j<kl; j++){
			printf("\nJob Type (1/2): "); 
			scanf("%d", &ay);
			if(ay==1){
				printf("Enter Query Id: "); 
				scanf("%d", &f[kp].process_id);
				printf("Enter Arrival Time: "); 
				scanf("%d", &t);
				if(t<1000 || t>1200){
					printf("\nEnter Correct time");
					get();
				}
				else{f[kp].a_time= t-1000;}
				printf("Bust Time: "); 
				scanf("%d", &f[kp].b_time);	 
				f[kp].kt= f[kp].b_time; 
				kp++;
			} else{
				printf("Enter Query Id: "); 
				scanf("%d", &s[ml].process_id);
				printf("Enter Arrival Time: "); 
				scanf("%d", &t); 
				if(t<1000 || t>1200){
					printf("\nEnter Correct time\n");
					get();
				}
				else {s[ml].a_time= t-1000; }
				printf("Bust Time: "); 
				scanf("%d", &s[ml].b_time);	 
				s[ml].kt= s[ml].b_time;
				ml++;
			}
		}
	}
}

void header(){
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\t\tWELCOME TO ONLINE QUERIES SYSTEM                             ***\n");
	printf("\t\t\t\t\t***\t\t\t\t   LINUX EXPERT SUDESH SHARMA                                ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\nPlease follow following instruction given below\n"
			"\n->All the t Enter in 2400 hours format. For Example, if time is 10:30 am then enter 1030\n"
			"\n->A;ll the Queries are handle only between 10:00 am to 12:00 am\n"
			"\n->Enter all the arrival times in ascending order\n"
			"\n->Here all the Time units are in minutes. \n"
			"\n->At the field of job type enter 1 for faculty queries and 2 for student queries\n\n\n"
			);
}

 main(){
 	header();
	get();
	join();
	r_robin();
	display();
}
