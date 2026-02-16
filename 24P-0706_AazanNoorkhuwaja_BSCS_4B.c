
// Name:Aazan Noor Khuwaja
// Roll No:24P-0706
// Section:4B
// Course:Operating System
// Assignment:1


#include<unistd.h>//this is headerfile which contaions system call functions read and write functions.
int main(){
    //here first we need a buffer where we can store inputs from keyboard and all inputs in string format not in int.
    char buff[100];
    //STDOUT_FILENO whose value = 1 means to print on screen then the txt which we will show and then we have its length.
    write(STDOUT_FILENO,"Enter the first number: ",24);
    //STDIN_FILENO value = 0 means to get input from keyboard.
    read(STDIN_FILENO,buff,100);
    //here used buff length 100 to read because we can have inputs from keyboard which are under buffer capacity.

    //To convert from string to int using ascii values
    int i=0,num_1,temp_1=0;
    //here using \n because enter key stored as newline in buffer when we get \n this is last char till to that we have to covert to int not \0 because read system call donot adds \0 (null) at end it adds \n when enter pressed after string completes..
    while(buff[i]!='\n')
    { 
        //as in ascii first char is '1' which in ascii 49 and subtracting '0' from it whose ascii is 48 then in num_1 we will have 1 int.
        num_1=buff[i]-'0';
        //to combine digits if number is of two digit or 3 digit.
        temp_1=(temp_1*10)+num_1;
        i+=1;
    }
    int n1=temp_1; //the actual int value storing in n1.


    write(STDOUT_FILENO,"Enter the second number: ",25);
    read(STDIN_FILENO,buff,100);
    //to convert second string to int
    int j=0,num_2,temp_2=0;
      //same approach just changed int variables taking separate not usning previous ones.
    while(buff[j]!='\n')
    {
        num_2=buff[j]-'0';
        temp_2=(temp_2*10)+num_2;
        j+=1;
    }
    int n2=temp_2;


    int sum=n1+n2; 
    
    //now n1 , n2 and sum all are in int as to print on screen using write system call we need to convert them back to string.
    int k=0;
    //using do while so that it runs even when n1 is 0 at start.
    do{
        int digit=n1%10;
        char character=digit+'0';
        buff[k]=character;
        k++;
        n1=n1/10;
    }while(n1!=0);

    write(STDOUT_FILENO,"The sum of ",11);
    
    /*here as the string we get from each digit will be in reverse order like '2','1' in buffer to print that we will loop in reverse from last index where '1' to first index where '2'.
    and as we counted each digit using k,so in k we have length of string in buffer. */
    while(k>0)
    {
    k--;
    write(STDOUT_FILENO,&buff[k],1); //here passing as address of first char of buffer because the reciever is pointer which recieves address not direct variable.
    }


    write(STDOUT_FILENO," and ",5);

    //same approach continues for 13
    k=0;
    do{
        int digit=n2%10;
        char character=digit+'0';
        buff[k]=character;
        k++;
        n2=n2/10;
    }while(n2!=0);


    while(k>0){
    k--;
    write(STDOUT_FILENO,&buff[k],1);
    }

    // and here same for sum.
        k=0;
    do{
        int digit=sum%10;
        char character=digit+'0';
        buff[k]=character;
        k++;
        sum=sum/10;
    }while(sum!=0);

write(STDOUT_FILENO," is ",4);

    while(k>0){
    k--;
    write(STDOUT_FILENO,&buff[k],1);
    }
    
    //printing newline to so to avoid curser of username in terminal after output.
    write(STDOUT_FILENO,"\n",1);

    return 0;
}