#include<stdio.h>
#include<conio.h>
#include<graphics.h>	// for graphics
#include<dos.h>		// for delay() function
#include<stdlib.h>	// for rand() function
#include<time.h>	// for time function
//#include<windows.h>

// Global variables
int i = 0, j = 0, page = 0;

// Function to draw lines according to array
void drawLine(int arr[], int len)
{
	int i, j = 0;
	for(i=0;i<len*2;i=i+2)
	{
		setcolor(GREEN);
		line(i+200, 340, i+200, 340 - arr[j]);
		j++;
	}
}

// Function to get the random array of integers
void getRandomArray(int arr[], int len, int upper, int lower)
{
	srand(time(0));

	for(i = 0;i < len; i++)
	{
		arr[i] = rand() % (upper - lower + 1) + lower;
	}
}

// Function to swap the array nos.
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Bubble Sort logic
void bubbleSort(int arr[], int len)
{
	for(i=0;i<len-1;i++)
	{
		setvisualpage(1 - page);
		for(j=0;j<len-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
//		setvisualpage(1 - page);
		cleardevice();
//		clearviewport();
		setcolor(YELLOW);
		outtextxy(50, 100, "Bubble Sort");
		drawLine(arr, len);
		setactivepage(page);
		page = 1 - page;
		delay(50);
	}
//	setvisualpage(page);
	setvisualpage(1 - page);
}

// Selection sort logic
void selectionSort(int arr[], int len)
{
	int min, i, j;
	for(i=0;i<len-1;i++)
	{
		min = i;
		setvisualpage(1 - page);
		for(j=i+1;j<len;j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
//		setvisualpage(1 - page);
		cleardevice();
		setcolor(YELLOW);
		outtextxy(50, 100, "Selection Sort");
		drawLine(arr, len);
		setactivepage(page);
		page = 1 - page;
		delay(50);
	}
	setvisualpage(1 - page);
//	setvisualpage(0);
}

// Function to ask the user about the choices
void askChoices(int arr[], int len, int upper, int lower, int flag)
{
	int ch;
	char c;
	printf("\n1.Bubble Sort\n2.Selection Sort\n3.Shuffle\n4.Exit");
	printf("\nEnter the Choice:");
	scanf("%d", &ch);
	switch(ch)
	{
	case 1:
		if(flag == 0)
		{
			bubbleSort(arr, len);
			flag = 1;
			clrscr();
			cleardevice();
			drawLine(arr, len);
			askChoices(arr, len, upper, lower, flag);
			break;
		}
		else
		{
			printf("Already Sorted!\nShuffle the array!");
			printf("\nDo you want to\n  shuffle the array?(Y/N):");
			scanf("%s", &c);
			if(c == 'y' || c == 'Y')
			{
				clrscr();
				cleardevice();
				getRandomArray(arr, len, upper, lower);
				flag = 0;
				drawLine(arr, len);
				askChoices(arr, len, upper, lower, flag);
				break;
			}
			else
			{
				clrscr();
				cleardevice();
				drawLine(arr, len);
				askChoices(arr, len, upper, lower, flag);
				break;
			}
		}
	case 2:
		if(flag == 0)
		{
			selectionSort(arr, len);
			flag = 1;
			clrscr();
			cleardevice();
			drawLine(arr, len);
			askChoices(arr, len, upper, lower, flag);
			break;
		}
		else
		{
			printf("Already Sorted!\nShuffle the array!");
			printf("\nDo you want to\n  shuffle the array?(Y/N):");
			scanf("%s", &c);
			if(c == 'y' || c == 'Y')
			{
				clrscr();
				cleardevice();
				getRandomArray(arr, len, upper, lower);
				flag = 0;
				drawLine(arr, len);
				askChoices(arr, len, upper, lower, flag);
				break;
			}
			else
			{
				clrscr();
				cleardevice();
				drawLine(arr, len);
				askChoices(arr, len, upper, lower, flag);
				break;
			}
		}
	case 3:
		clrscr();
		cleardevice();
		getRandomArray(arr, len, upper, lower);
		flag = 0;
		drawLine(arr, len);
		askChoices(arr, len, upper, lower, flag);
		break;
	case 4:
		exit(0);
	default:
		break;
	}

}

int main()
{
	int i, ch, flag = 0;
//	int gd = DETECT, gm, errorcode;
	int gd = EGA, gm = EGAHI, errorcode;
	int upper = 340, lower = 10;
	int arr[210];
	int len = sizeof(arr) / sizeof(arr[0]);
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
//	clrscr();
//	cleardevice();
	setbkcolor(BLACK);

	 /* read result of initialization */
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		   printf("Graphics error: %s\n", grapherrormsg(errorcode));
		   printf("Press any key to halt:");
		   getch();
		   exit(1);  /* terminate with an error code */
	}

	getRandomArray(arr, len, upper, lower);
	drawLine(arr, len);
	askChoices(arr, len, upper, lower, flag);

	getch();
	closegraph();

	return 0;
}
