/*
 * IMPORTANT: WRITE YOUR NAME AND NetID BELOW.
 * 
 * Last Name: Mantri
 * First Name: Samira
 * Netid:sm6412
 * 
 * You will do your project in this file only.
 * Do not change function delarations. However, feel free to add new functions if you want.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* Function declarations: do not change that, but you may add your own functions */
void arrange(int *, int);
void find_fibonacci(int, int);
void flipping(unsigned int);
void file_histogram(char *);
void file2upper(char *);
void file_encrypt(char *);


/* Add here function declarations of your own, if any. */



/*********************************************************************************/

/* 
 * Do  NOT change anything in main function 
 */
int main(int argc, char * argv[])
{
  int option = 0;
  int i, j;
  int * list;
  
  if(argc < 2 )
  {
     fprintf(stderr,"Usage: lab1 num [input]\n");
     fprintf(stderr,"num: 1, 2, 3, 4, 5, or 6\n");
     exit(1);
  }
  
  option = atoi(argv[1]);
  
  switch(option)
  {
    case 1: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 1 num\n");
	      fprintf(stderr,"num: number of elements of the array to be arranged\n");
	      exit(1);
	    }
	    j = atoi(argv[2]);
	    list = (int *)malloc(j*sizeof(int));
	    if(!list)
	    {
	      fprintf(stderr,"Cannot allocate list in option 1\n");
	      exit(1);
	    }
	    
	    /* Gnerate random numbers in the range [0, 100) */
	    for(i = 0; i < j; i++)
	      list[i] = rand()% 100;
	    
	    /* Print the unsorted array */
	    printf("The original array:\n");
	    for(i = 0; i < j; i++) 
	      printf("%d ", list[i]);
	    printf("\n");
	    
	    printf("The arranged array:\n");
	    arrange(list, j);
	    
	    break;
	    
	    
    case 2: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 2 x y\n");
	      fprintf(stderr,"x and y: positive integers and x < y and y < 1 million\n");
	      exit(1);
	    }
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    
	    find_fibonacci(i, j);
	    
	    break;

	    
    case 3: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 3 num\n");
	      fprintf(stderr,"num: unsigned intger number\n");
	      exit(1);
	    }
	    
	    flipping( atof(argv[2]));
	    
	    break; 
	    
	    
    case 4: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 4 filename\n");
	      exit(1);
	    }
	    
	    file_histogram(argv[2]);
	    
	    break;

	    
    case 5: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 5 filename\n");
	      exit(1);
	    } 
	    
	    file2upper(argv[2]);
	    
	    break;

	    
    case 6: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 46filename\n");
	      exit(1);
	    }
	    
	    file_encrypt(argv[2]);
	    
	    break;	      
	    
    default: fprintf(stderr, "You entered an invalid option!\n");
	     exit(1);
  }
  
  return 0;
}

/******* Start filling the blanks from here and add any extra functions you want, if any *****/

/*
 * Part 1:
 * In this function, you are given two inputs:
 * inputs: 
 * 	an array of int list[] 
 * 	The number of elements in that array: num
 * You need to put the even numbers first (if any), sorted in ascending order, followed
 * by the odd numbers (if any) sorted in ascending order too.
 * Example: a list of 5 elements: 5 4 3 2 1 
 * The output will be: 2 4 1 3 5 
 * Finally, print the array on the screen.
 * */
void arrange(int *list, int num)
{
    // creat an even counter
    int even=0;
    // create an odd counter
    int odd=0;
  
    int x;
    int e;
    int checker;
    
    // move through the list and count even and odd numbers
    for (x=0;x<num;x++){
        int checker= list[x];
        if(checker%2!=0){
            int w=0;
	    odd++;
            for(w=x+1;w<num;w++){
                if(list[w]%2==0){
                    int temp=list[w];
                    list[w]=list[x];
                    list[x]=temp;
                }
            }
        }
     }
    
    
    
    
    // build even araray
    for(e=0;e<num;e++){
      int checker=list[e];
      if(checker%2==0){
	even++;
      }
    }
    
    // set odd equal to num of noneven nums 
    odd=num-even;
    
   
    // create even and odd arrays
    int *even_list;
    even_list=(int *)malloc(even*sizeof(int));
    int *odd_list;
    odd_list=(int *)malloc(odd*sizeof(int));
    
    // build even array
    int count;
    for(count=0;count<even;count++){
      even_list[count]=list[count];
    }
    
    // build odd arrray
    int t=0;
    for(count=0;count<num;count++){
      checker=list[count];
      if(checker%2!=0){
	odd_list[t]=list[count];
	t++;
	 
      }
    }
    
    
    //sort even and odd arrays
    int i, m, min_index;
 
    // sort even array
    for (i = 0; i < even-1; i++)
    {
        
        min_index = i;
        for (m = i+1; m < even; m++)
          if (even_list[m] < even_list[min_index])
            min_index = m;
 
        
	int temp;
        temp=even_list[min_index];
	even_list[min_index]=even_list[i];
	even_list[i]=temp;
    }
    
    // print sorted even numbers 
    for(x=0;x<even;x++){
      printf("%d ",even_list[x]);
    }
    
     // One by one move boundary of unsorted subarray
    for (i = 0; i < odd-1; i++)
    {
        // Find the minimum element in unsorted array
        min_index = i;
        for (m = i+1; m < odd; m++)
          if (odd_list[m] < odd_list[min_index])
            min_index = m;
 
        // Swap the found minimum element with the first element
	int temp;
        temp=odd_list[min_index];
	odd_list[min_index]=odd_list[i];
	odd_list[i]=temp;
    }
    
    // printed sorted odd numbers 
    for(x=0;x<odd;x++){
      printf("%d ",odd_list[x]);
    }
    
   
   printf("\n");
   
   // free memory
   free(even_list);
   free(odd_list);
 
  
  
     
      
  
  
}

 


/*********************************************************************************/

/* 
 * Part 2:
 * In this part, you are given two positive integer, x and y, larger than 0.
 * You need to print all the Fibonacci numbers between x and y (NOT including x and y themselves), if any.
 */
void find_fibonacci(int x, int y)
{
  int i;
  int num1=0;
  int num2=1;
  int next=num1+num2;
  
  // set numbers that cannot be printed
  int start=x;
  int finish=y;
  
  if(num2>start){
    printf("%d ",num2);
  }
  
  // calculate and print fibonacci numberrs
  while(next <= finish){
    num1=num2;
    num2=next;
    next=num1+num2;
    if(next > start && next<finish){
      printf("%d ",next);
    }
    
  }
  printf("\n");
  
  
  
}


/*********************************************************************************/

/*
 * Part 3:
 * Given an unsigned integer (so has values of 0 and up), print on the screen 
 * the flipping of that number.
 * That is, if the number given is: 1234  then you print: 4321
 */
void flipping(unsigned int num)
{
  // take off the last int 
  int checker= num/10;
   
  if(checker==0){
    printf("%d",num);
    printf("\n");
    return;
  }
  
  // print last int
  printf("%d",num%10);
  flipping(checker);
  
  
    
 
  
}

/*********************************************************************************/

/*
 * Part 4
 * The input is a filename.
 * The filename contains a string of characters (can be upper case letters, lower case letters, numbers, ...).
 * The output is a histogram of the file printed on the screen ONLY for lower case letters.
 * Example: 
 * The input file in.txt contains:  a1aaAbBBb709bbc
 * The output will be:
 * a: 3
 * b: 4
 * c: 1
 * .... and so one
 * The file can contain any characters, not necessarily only lower case characters.
 */
void file_histogram(char *filename)
{
  // create list
  char *list;
  list=(char *)malloc(sizeof(char));
  
  // open file and read its contents 
  FILE *file = fopen(filename,"r");
  fgets(list,4000,file);
  
  // create an array to contain letters and fill it with letters
  int letters[26];
  int placer=97;
  int i;
  for(i=0;i<26;i++){
    letters[i]=placer;
    placer++;
  }

  // create an array to contain the number of times a letter is read
  int counter[26];
  for(i=0;i<26;i++){
    counter[i]=0;
    placer++;
  }
  
  
  
  
  int z;
  // read through list and find how many times a letter appears
  for(i=0;i<strlen(list);i++){
    if(list[i]==0){
       break;
   }
   int checker=0;
    if(list[i]>=97&&list[i]<=122){
	for(z=0;z<26;z++){
	  if(letters[z]==list[i]){
	    counter[checker]=counter[checker]+1;
	    break;
	  }
	  else{
	    checker++;
	  }
	}
    }
  }
  
  
  // print letters and how many times they occur
  int q;
  for(q=0;q<26;q++){
    char *point=&letters[q];
    printf("%c: ",*point);
    printf("%d\n",counter[q]);
  }
  
  // close file
  close(file);
 
  
}

/*********************************************************************************/

/* 
 * Part 5:
 * Input: filename
 * Output:filenameCAPITAL
 * The output files contains the same characters as the input file but in upper case.
 * The input file will ONLY contain lower case letters and no spaces.
 * If the input filename is: mmmm 
 * The output filename is: mmmmCAPITAL
 */
void file2upper(char *filename)
{
    // create a file to contain the contents of the input file
    FILE *file1;
    char *file_ptr=(char *)malloc(sizeof(char));
    
    // open file
    file1=fopen(filename,"r");
    fscanf(file1,"%s",file_ptr);
    
    
    // create new file name with CAPITAL added to the end 
    char *newname=(char *)malloc(sizeof(char));
    strcat(newname,filename);
    strcat(newname,"CAPITAL");
    
    // create a new file
    FILE *file2;
    
    // open file so characters can be written to it 
    file2= fopen(newname,"w");
    
    int i;
    // create new uppercase characters and add to new file 
    for(i=0;i<strlen(file_ptr);i++){
      int upper=file_ptr[i]-('a'-'A');
      char *point=upper;
      fprintf(file2,"%c",point);
    }
    
    
    // close files
    close(file1);
    close(file2);
    
    // free space 
    free(newname);
  
  
  
}

/*********************************************************************************/

/*
 * Part 6:
 * In that last part, you will learn to implement a very simple encryption.
 * Given a file that contains a series of lower case charaters (may be separated by white space),
 * replace all non-white space with the lower case letter that exists 3 letters before, in a circular way.
 * For example: 
 * e will be replaced with b
 * d will be replaced with a 
 * c will be replaced with z  <--- circular
 * b will be replaced with y  <--- circular
 * and white spaces will be left unchanged.
 * Print the output on the screen.
 */
void file_encrypt(char * filename)
{
  // create a list to contain the input file's contents 
  char *list;
  list=(char *)malloc(sizeof(char)*1000);
  
  // open file
  FILE *file = fopen(filename,"r");
  fgets(list,4000,file);
  
  // convert characters into the character 3 places before them 
  // and print them
  int i;
  for(i=0;i<strlen(list);i++){
      // leave spaces alone
      if(list[i]==32){
          char *point=&list[i];
	  printf("%c",*point);
	  continue;
      }
      else{
	  // turn a into x
          if(list[i]==97){
              list[i]=120;
	      char *point=&list[i];
	      printf("%c",*point);
          }
          // turn b into y
          else if(list[i]==98){
              list[i]=121;
	      char *point=&list[i];
	      printf("%c",*point);
          }
          // turn c into z
          else if(list[i]==99){
              list[i]=122;
	      char *point=&list[i];
	      printf("%c",*point);
          }
          else{
              int new_num=list[i]-3;
	      list[i]=new_num;
	      char *point=&list[i];
	      printf("%c",*point);
          }
          
      }
  }
  // close file
  close(file);
  printf("\n");
 }