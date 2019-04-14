#include<stdio.h>
#include<string.h>
#include<conio.h>
struct p_Struct {
    char p_name[20];
    int a_time, b_time, c_time, left;
}temp_Struct;


void f_queue(int process) {

    int i, a_time, b_time, q_time;
    struct p_Struct f_process[process];

    for(i = 0; i < process; i++) {
        printf("Enter the details of Process[%d]", i+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", f_process[i].p_name);

        printf("Arrival Time : ");
        scanf("%d", &f_process[i].a_time);

        printf("Burst Time : ");
        scanf("%d", &f_process[i].b_time);
        puts("");
    }
    printf("Now, enter the Time Quantum for FACULTY queue : ");
    scanf("%d", &q_time);
    for(i = 0; i < process; i++) {
        for(int x = i +1; x < i; x++){
            if(f_process[i].a_time > f_process[x].a_time) {
                temp_Struct = f_process[i];
                f_process[i] = f_process[x];
                f_process[x] = temp_Struct;
            }
        }
    }
    for(i = 0; i < process; i++) {
        f_process[i].left = f_process[i].b_time;
        f_process[i].c_time = 0;
    }

    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;

    
    int flag, x, n, z, waiting_time = 0;
    do {
        for(i = 0; i < process; i++){
            if(total_time >= f_process[i].a_time){
                z = 0;
                for(x = 0; x <= queue; x++) {
                    if(round_robin[x] == i) {
                        z++;
                    }
                }
                if(z == 0) {
                    queue++; 
                    round_robin[queue] == i;
                }
            }
        }

        if(queue == 0) {
            n = 0;
        }
        if(f_process[n].left == 0) {
            n++ ;
        }
        if(n > queue) {
            n = (n - 1) % queue;
        }
        if(n <= queue) {
            if(f_process[n].left > 0) {
                if(f_process[n].left < q_time){
                    total_time += f_process[n].left;
                    f_process[n].left = 0;
                }else {
                    total_time += q_time;
                    f_process[n].left -= q_time;
                }
                f_process[n].c_time = total_time;
            }
            n++;
        }
        flag = 0;
        
        for(i = 0; i < process; i++) {
            if(f_process[i].left > 0) {
                flag++;
            }
        }
    }while(flag != 0);


    printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\tWELCOME TO Round ROBIN SCHEDULING ALGORITHM                  ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t***\t\t\t\t\t\t\t\t\t\t                     ***\n");
	printf("\t\t\t\t\t************************************************************************************************\n");
	printf("\t\t\t\t\t************************************************************************************************\n");
    printf("\n|\tProcess Name\t  |\tArrival Time\t  |\tBurst Time\t |\tCompletion Time  \t|\n");

    for(i = 0; i < process; i++){
        waiting_time = f_process[i].c_time - f_process[i].b_time - f_process[i].a_time;

        printf("\n|\t  %s\t    |\t  %d\t   |\t  %d\t   |\t  %d\t   |\n", f_process[i].p_name, f_process[i].a_time, f_process[i].b_time, f_process[i].c_time);
    }

}


void student_Queue(int process) {

    int i, a_time, b_time, q_time;
    struct p_Struct student_Process[process];

    for(i = 0; i < process; i++) {
        printf("Enter the details of Process[%d]", i+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", student_Process[i].p_name);

        printf("Arrival Time : ");
        scanf("%d", &student_Process[i].a_time);

        printf("Burst Time : ");
        scanf("%d", &student_Process[i].b_time);
    }
    printf("Now, enter the Time Quantum for STUDENT queue : ");
    scanf("%d", &q_time);
    for(i = 0; i < process; i++) {
        for(int x = i +1; x < i; x++){
            if(student_Process[i].a_time > student_Process[x].a_time) {
                temp_Struct = student_Process[i];
                student_Process[i] = student_Process[x];
                student_Process[x] = temp_Struct;
            }
        }
    }
    for(i = 0; i < process; i++) {
        student_Process[i].left = student_Process[i].b_time;
        student_Process[i].c_time = 0;
    }

    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;
}


int main(int argc, char const *argv[]) {
    int select_queue, process;

    puts("Please choose a queue to post your query : ");
    puts("1. FACULTY queue.");
    puts("2. STUDENT queue.");
    printf("> ");
    scanf("%d", &select_queue);

    switch(select_queue) {
        case 1 :
                printf("Enter number of process for FACULTY queue : ");
                scanf("%d", &process);
                
                f_Queue(process);
                
                break;

        case 2 :
                printf("Enter number of process for STUDENT queue : ");
                scanf("%d", &process);

                student_Queue(process);
                
                break;

        default : 
                printf("Please selet the correct option by running the program again.");
    }

    return 0;
}
