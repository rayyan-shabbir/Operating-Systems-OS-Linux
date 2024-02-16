#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include<pthread.h>
#include<unistd.h>

struct student
{
    char *name;
    char *rollno;
    float marks;
};
void * viva(void *args)
{
    struct student *info = (struct student *)args; //We have to typecast the void * back to struct student * so that we can use it properly...
    //asking questions ... etc .. viva business logic code...
    info->marks = 95.0;
}
int main(void)
{
    struct student s1, s2;
    /*Since pthread_create single argument for the thread function in order to pass the multiple arguments we pass struct*/
    pthread_t t1, t2; //id forthreads..
    //Adding data to student struct s1..
    s1.name = "Rayan";
    s1.rollno = "BITF20M535";
    s1.marks = 0.0;
    //Adding data to studet struct s2..
    s2.name = "Hassan";
    s2.rollno = "BITF20A516";
    s2.marks = 0.0;
    fprintf(stdout,"Marks before calling viva threads\n");
    fprintf(stdout, "Struct S1\nStudent Name: %s\nStudent RollNo: %s\nStudent Marks: %0.2f\n", s1.name, s2.rollno, s1.marks);
    fprintf(stdout, "Struct S1\nStudent Name: %s\nStudent RollNo: %s\nStudent Marks: %0.2f\n", s2.name, s2.rollno, s2.marks);
    pthread_create(&t1, NULL, viva, (void *)&s1); //notice the type casting of struct student * to the void * 
    pthread_create(&t2, NULL, viva, (void *)&s2); //notice the type casting of struct student * to the void *
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    fprintf(stdout,"Marks After calling viva threads\n");
    fprintf(stdout, "Struct S1\nStudent Name: %s\nStudent RollNo: %s\nStudent Marks: %0.2f\n", s1.name, s2.rollno, s1.marks);
    fprintf(stdout, "Struct S1\nStudent Name: %s\nStudent RollNo: %s\nStudent Marks: %0.2f\n", s2.name, s2.rollno, s2.marks);

    return 0;
}