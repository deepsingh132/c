//COPYRIGHT PROJECT,DON'T REDISTRIBUTE,COPY,REPLACE OR MODIFY !//

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<graphics.h>
//#include<password.h>
#include<fstream.h>
char array[900*1024*1*024]={0,1};//to increase
				  // the size of the program
				  //just to brag
char file1[]="stud.txt";
char file2[]="stud2.txt"; //global variables
char file3[]="stud3.txt";
char file4[]="stud4.txt";
char str[100];
char str2[100];
char rates;
int rate1;
int rate2;
int rate3;
int rate4;
int rate5;
int flag;
int noFlag;
 union REGS i,o;  //unions for mouse function
 union REGS in,out;
 initmouse() //initialization of mouse interrupts by int86 function
{
i.x.ax=0;
int86(0x33,&i,&o);
return(o.x.ax);
}
struct BMP    //defining structure for image data
    {
      char Type[2];           //File type. Set to "BM".
      unsigned long Size;     //Size in BYTES of the file.
      unsigned long Reserved;      //Reserved. Set to zero.
      unsigned long OffSet;   //Offset to the data.
      unsigned long headsize; //Size of rest of header. Set to 40.
      unsigned long Width;     //Width of bitmap in pixels.
      unsigned long Height;     //  Height of bitmap in pixels.
      unsigned int  Planes;    //Number of Planes. Set to 1.
      unsigned int  BitsPerPixel;       //Number of Bits per pixels.
      unsigned long Compression;   //Compression. Usually set to 0.
      unsigned long SizeImage;  //Size in bytes of the bitmap.
      unsigned long XPixelsPreMeter;     //Horizontal pixels per meter.
      unsigned long YPixelsPreMeter;     //Vertical pixels per meter.
      unsigned long ColorsUsed;   //Number of colors used.
      unsigned long ColorsImportant;  //Number of "important" colors.
    };
struct ratings  //structure for ratings
 {
 char rate;
 };
class front_end   //defining class for frontend
{
   public:

	   void showmouseptr()  //function to show mouse
	   {
	     i.x.ax=1;
	     int86(0x33,&i,&o);
	   }
	   void hidemouseptr()  //function to hide mouse
	   {
	     i.x.ax=2;
	     int86(0x33,&i,&o);
	   }

   void intro()      //intro function
   {
      int x=getmaxx()/2;
      int y=getmaxy()/2;

      loading_Screen();

      cleardevice();     //clearing screen
      setcolor(3);

      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2); //setting font
      settextjustify(x,y);        //center text

      outtextxy(x-50,y-60,"WELCOME");
      delay(150);

      outtextxy(x-40,y-20,"TO");
      delay(150);

      outtextxy(x-10,y-20,"THE");
      delay(150);

      outtextxy(x-82,y+15,"SEARCH ENGINE");
      delay(150);

      outtextxy(x-80,y+50,"BY HACK BABA");
      delay(150);

      outtextxy(x-90,y+80,"#KIRPA BARSEGI");
      delay(150);

      outtextxy(x+100,y+80,"^_^");

      delay(3000);
      cleardevice();
  }
  void intro_Text()      //function to show info in intro
  {
	 int x=getmaxx()/2;
	 int y=getmaxy()/2;


	 outtextxy(x-50,y-235,"MY MENTOR");

	 outtextxy(x-80,y+120,"Deepak Jain Sir");

	 outtextxy(x+80,y+150,"SUBMITTED BY:");

	 outtextxy(x+200,y+150,"MANDEEP SINGH");

	 outtextxy(x+115,y+160,"CLASS");

	 outtextxy(x+176,y+160,":");

	 outtextxy(x+200,y+160,"X||-B");
  }

  void main_SearchBox()  //defining main searchbox
  {
     settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

     int left,right,top,bottom;

     left=getmaxx()/2-300;
     top= getmaxy()/2-10;
     right=getmaxx()/2+300;
     bottom=getmaxy()/2+20;

     setcolor(56);
     rectangle(left,top,right,bottom); //searchbox
  }
  void icon()       // main icon
  {
      int x=getmaxx()/2;
      int y=getmaxy()/2;

    setcolor(1);
    settextstyle(SMALL_FONT, HORIZ_DIR,15);

    outtextxy(x-250, y-80,"D");
    setcolor(4);

    outtextxy(x-190,y-80,"E");
    setcolor(62);

    outtextxy(x-120,y-80,"E");
    setcolor(1);

    outtextxy(x-50,y-80,"P");
    setcolor(2);

    outtextxy(x+30,y-80,"S");
    setcolor(4);

    outtextxy(x+100,y-80,"O");
    setcolor(1);

    outtextxy(x+150,y-80,"F");
    setcolor(2);

    outtextxy(x+200,y-80,"T");
    setcolor(4);

    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  }

  int pixel(int x1, int y1, char* FileName) //function to show image
    {
	int b,a;
	struct  BMP Obj; //getting variables from structure

	unsigned char* Datas;
	int in=0;
	unsigned char c=0;
	FILE * fp;    //assigning file to pointer fp

	fp = fopen(FileName,"rb");  //opening file
	if(!fp){
	printf("Error : Unable to open file ..");//if unable to open file
	exit(0);
	}

	fread(&Obj, sizeof(Obj), 1, fp);
	if(Obj.BitsPerPixel!=4)  // This isn't a 16 color bmp we can read;
	{
	 fclose(fp);
	 printf("Error : File format not supported ..");
	 exit(0);
	};
	intro_Text();       //showing intro text
	fseek(fp,Obj.OffSet,SEEK_SET);
	Datas=(unsigned char*) calloc(Obj.Width/2+1, sizeof(unsigned char));
	for(b=Obj.Height;b>=0;b--)
	{
	 fread(Datas, sizeof(unsigned char), Obj.Width/2, fp);
	 c=0;
	 in=0;
	 for(a=0;a<=Obj.Width;a+=2)//A+=2
	 {
	     c = (Datas[in] | 0x00) >>4;
	     putpixel(a+x1,b+y1,c);//drawing image pixel by pixel on screen
	     c = (Datas[in] | 0xF0) & 0x0F;
	     putpixel(a+1+x1,b+y1,c);
	     in++;
	 }

	 }
	free (Datas); //freeing allocated blocks of data
	fclose(fp);
	//getch();
	return 1;
    }
    void iconSmall()   //small icon function
    {
       int x=getmaxx()/2;
       int y=getmaxy()/2;

       settextstyle(DEFAULT_FONT, HORIZ_DIR,1);

       outtextxy(x-50,y-235,"D");
       setcolor(4);

       outtextxy(x-40,y-235,"e");
       setcolor(62);

       outtextxy(x-30,y-235,"e");
       setcolor(1);

       outtextxy(x-20,y-235,"p");
       setcolor(2);

       outtextxy(x-10,y-235,"S");
       setcolor(4);

       outtextxy(x-0,y-235,"o");
       setcolor(3);

       outtextxy(x+10,y-235,"f");
       setcolor(2);

       outtextxy(x+20,y-235,"t");
       setcolor(4);

    }
    void search_Area()  //search area function
    {

	     int left3=getmaxx()/2-302;
	     int top3=getmaxy()/2-130;
	     int right3=getmaxx()/2+302;
	     int bottom3=getmaxy()/2+225;

	     settextstyle(DEFAULT_FONT, HORIZ_DIR,1);


	     rectangle(left3,top3,right3,bottom3); //FOR THE SEARCH AREA
    }
    void search_Window() // search window function
    {

      int left,right,top,bottom;
      settextstyle(DEFAULT_FONT, HORIZ_DIR,1);

      setcolor(56);
      setbkcolor(WHITE);// setting background color to white

      left=getmaxx()/2-312;
      top=getmaxy()/2-238;
      right=getmaxx()/2+312;
      bottom=getmaxy()/2+235;

      rectangle(left,top,right,bottom);  //FOR THE WINDOW
    }
    void search_Box() //search box function
    {

       int x=getmaxx()/2;
       int y=getmaxy()/2;

       settextstyle(DEFAULT_FONT, HORIZ_DIR,1);

       int left2=20;
       int top2= 25-10;
       int right2=80+500;
       int bottom2=25+20;

       setcolor(1);

       rectangle(left2,top2,right2,bottom2); //FOR THE SEARCH BOX

       setlinestyle(SOLID_LINE,0,1);
       settextstyle(GOTHIC_FONT, HORIZ_DIR,3);

       setcolor(4);
       outtextxy(x+220,y-225,"D");

       setcolor(2);
       outtextxy(x+235,y-225,".");

       setcolor(3);
       outtextxy(x+240,y-225, "S");

       setcolor(1);
    }
    void underThe_Box()//function for all the the things under searchbox
    {
       int x=getmaxx()/2;
       int y=getmaxy()/2;

       settextstyle(DEFAULT_FONT,HORIZ_DIR,1);


       line(7,50,630,50);
       setcolor(BLUE);

       outtextxy(x-300,y-176,"ALL");
       outtextxy(x-306,y-170,"_____");

       setcolor(LIGHTGRAY);

       outtextxy(x-150,y-176,"IMAGES");
       outtextxy(x+0,y-176,"WEB");
       outtextxy(x+150,y-176,"VIDEOS");

       setcolor(DARKGRAY);
       line(7,80,630,80);
    }
    void loading_Screen() // loading screen function
    { //int gd=DETECT,gm;

      //variables for arcs
      int x=317,y=236;
      int v1=0,v2=0,v3=0,num=0,n=0;

      while(num<=100)
      {
	  cleardevice();
	  //show loaded percent
	  gotoxy(40,15);
	  cout<<num<<"%";

	  setcolor(YELLOW);
	  outtextxy(282,80,"Loading..");

	  //draw the arcs
	  setlinestyle(0,0,3);
	  setcolor(GREEN);
	  arc(x,y,270+v2,90+v2,40);
	  setcolor(LIGHTRED);
	  arc(x,y,320-v2,120-v2,70);
	  arc(x,y,320-v2,120-v2,72);
	  setcolor(CYAN);
	  arc(x,y,30+v1,160+v1,92);
	  setcolor(BLUE);
	  arc(x,y,270+v2,90+v2,40);
	  setcolor(5);

	  arc(x,y,300-v1,40-v1,111);
	  setcolor(RED);
	  arc(x,y,300+v3,140+v3,131);
	  arc(x,y,300+v3,140+v3,133);

  // assigning increase and decrease values to arc

	  v1+=4+rand()%8;
	  v2+=6+rand()%8;
	  v3+=3+rand()%8;
	  randomize();
	  n=rand()%2;
	  num=num+n;

	  delay(30);

	  if(num>=100)	//when loading gets completed
	  {
	      num+=0;
	      delay(500);
	      cleardevice();
	      setcolor(YELLOW);
	      outtextxy(200,150,"Loading Completed!!");
	      setcolor(MAGENTA);
	      outtextxy(180,300,"Press any key to exit..");
	  }
      }
   cleardevice();
    }
    void files_Available() //function to show files available
    {
       int x=getmaxx()/2;
       int y=getmaxy()/2;


       settextstyle(DEFAULT_FONT, HORIZ_DIR,1);

       line(17,365,620,365);
       outtextxy(x-290,y+130,"FILES AVAILABLE FOR SEARCH:");

       line(17,378,620,378);
       outtextxy(x-290,y+140,file1);

       line(17,387,620,387);
       outtextxy(x-290,y+150,file2);

       line(17,398,620,398);
       outtextxy(x-290,y+160,file3);

       line(17,408,620,408);
       outtextxy(x-290,y+170,file4);

       line(17,418,620,418);
    }
    void loading_Line() //function to show loading line
    {
       int a=getmaxx()/2;
       int b=getmaxy()/2;
       int c=90,i,z=50;
       setcolor(CYAN);

       outtextxy(a-110,b-140,"SEARCHING,PLEASE WAIT");
       setlinestyle(SOLID_LINE,0,2); //DOTTED,USERBIT,SOLID,CENTER,DASHED

       for(i=0;i<490;++i)
       {
	  delay(z);
	  setcolor(z);
	    if(z>=5)
	    {
	       z--;
	       setcolor(i);
	    }
       line(20,46,c,46);
       c++;
       }
    }
    void  main_Symbol()// main symbol function
    {
       int x=getmaxx()/2;
       int y=getmaxy()/2;


       setlinestyle(SOLID_LINE,0,1);
       settextstyle(GOTHIC_FONT, HORIZ_DIR,3);

       setcolor(4);

       outtextxy(x+260,y-10,"D");
       outtextxy(x+275,y-10,".");

       setcolor(3);
       outtextxy(x+280,y-10, "S");
    }
    int rect(int color,int x2,int y2,int x3,int y3)
    //function to fill button area
    {

      int i,j;

      for(i=x2;i<x3;i++)
      for(j=y2;j<y3;j++)
      putpixel(i,j,color);
      return 0;
    }
    int rect2(int color,int x2,int x3)
    {
      int i,j;
      for(i=x2;i<x3;i++)
      for(j=220;j<245;j++)
      putpixel(i,j,color);
      return 0;
    }
    int rect3(int color,int x2,int x3)
    {
      int i,j;
      for(i=x2;i<x3;i++)
      for(j=240;j<265;j++)
     putpixel(i,j,color);
     return 0;
    }
    int rect4(int color,int x2,int x3)
    {
      int i,j;
      for(i=x2;i<x3;i++)
      for(j=260;j<285;j++)
      putpixel(i,j,color);
      return 0;
    }
    int rect5(int color,int x2,int x3)
    {
      int i,j;
      for(i=x2;i<x3;i++)
      for(j=280;j<305;j++)
      putpixel(i,j,color);
      return(0);
    }

    void button(int x2,int y2,int x3,int y3,int cx,int cy)
    //button function
    {
      showmouseptr();
      setcolor(7);

      rectangle(x2,y2-1,x3,y3-1);
      rect(4,x2,y2,x3,y3);

      rectangle(x2,220,x3,245);
      rect2(60,x2,x3);

      rectangle(x2,240,x3,265);
      rect3(58,x2,x3);

      rectangle(x2,260,x3,285);
      rect4(2,x2,x3);

      rectangle(x2,280,x3,305);
      rect5(1,x2,x3);

      setcolor(63);

      outtextxy(x2+cx,190+cy,"1.*");
      outtextxy(x2+cx,210+cy,"2.**");
      outtextxy(x2+cx,230+cy,"3.***");  //ratings available
      outtextxy(x2+cx,250+cy,"4.****");
      outtextxy(x2+cx,270+cy,"5.*****");

      in.x.ax=0;
      int86(0x33,&in,&in);  //initializing mouse
      in.x.ax=1;
      int86(0x33,&in,&in);

      while(!kbhit())
      {

	 in.x.ax=3;
	 int x,y;
	 x2=in.x.cx;
	 y2=in.x.dx;
	 int86(0x33,&in,&out);
	 int86(0x33,&in,&in);

	 if(x2>199 && x2<281 && y2>199 && y2<223 && in.x.bx ==1)
	 {                         //getting mouse clicks
	      delay(300);
	      setcolor(63);
	      outtextxy(x2-50,y2-150,"MARJAA !");
	      rate1=1;

	      setcolor(63);

	      outtextxy(x2-100,y2-230,"THANKS FOR RATING THE SOFTWARE");
	      outtextxy(x2-100,y2-190,"YOUR RATINGS HAVE BEEN SAVED");
	 }

	 else if(x2>199 && x2<281 && y2>220 && y2<240 && in.x.bx ==1)
	 {
	      delay(300);
	      setcolor(63);
	      outtextxy(x2-50,y2-150,"CAN'T YOU BE NICE ?");
	      rate2=1;

	      setcolor(63);

	      outtextxy(x2-100,y2-230,"THANKS FOR RATING THE SOFTWARE");
	      outtextxy(x2-100,y2-190,"YOUR RATINGS HAVE BEEN SAVED");
	 }

	 else if(x2>199 && x2<281 && y2>240 && y2<260 && in.x.bx ==1)
	 {

	      delay(300);
	      setcolor(63);
	      outtextxy(x2-50,y2-150,"BUS ?");
	      rate3=1;

	      setcolor(63);

	      outtextxy(x2-100,y2-230,"THANKS FOR RATING THE SOFTWARE");
	      outtextxy(x2-100,y2-190,"YOUR RATINGS HAVE BEEN SAVED");
	 }

	 else if(x2>199 && x2<281 && y2>260 && y2<280 && in.x.bx ==1)
	 {

	      delay(300);
	      setcolor(63);
	 outtextxy(x2-50,y2-150,"KYA KAMI REH GAYI THI MERE SOFTWARE MAIN ?");
	      rate4=1;

	      setcolor(63);

	 outtextxy(x2-100,y2-230,"THANKS FOR RATING THE SOFTWARE");
	 outtextxy(x2-100,y2-190,"YOUR RATINGS HAVE BEEN SAVED");
	 }
	 else if(x2>199 && x2<281 && y2>280 && y2<305 && in.x.bx ==1)
	 {
	      delay(300);
	      setcolor(63);
	      outtextxy(x2-50,y2-150,"BALLE BALLE :)");
	      rate5=1;
	      setcolor(63);
	      outtextxy(x2-100,y2-230,"THANKS FOR RATING THE SOFTWARE");
	      outtextxy(x2-100,y2-190,"YOUR RATINGS HAVE BEEN SAVED");
	 }


      }
    }
    void showMouse_Graphics() //showing buttons
    {
       button(200,200,280,222,17,6);
       setcolor(8);

       in.x.ax = 1;
       int86 (0X33,&in,&out);

       getch();
    }
    void outro()  //outro function
    {
       cleardevice();

       setcolor(3);
       int x=getmaxx()/2;
       int y=getmaxy()/2;

       settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
       settextjustify(x,y);

       outtextxy(x-70,y-60,"THANK YOU");
       delay(150);

       outtextxy(x-60,y-20,"FOR");
       delay(150);

       outtextxy(x-5,y-20,"USING");
       delay(150);

       outtextxy(x-90,y+15,"THE SOFTWARE");
       delay(150);

       outtextxy(x-255,y+50,"PLEASE GIVE THE RATINGS ON THE NEXT PAGE:-");

       delay(2500);
       cleardevice();
       rating();
    }
    void rating()   //rating function
    {
       cleardevice();

       struct ratings r; //getting structure variables
       setbkcolor(CYAN);
       showMouse_Graphics();

       ofstream o;   //declaring ofstream variable o
       o.open("rating.dat",ios::out|ios::binary|ios::app);//opening file
							  //in append
							  //mode
       if(rate1==1) //getting the ratings
	 {
	   rates='1';
	   r.rate=rates;
	 }
       else if(rate2==1)
	 {
	   rates='2';
	   r.rate=rates;
	 }
       else if(rate3==1)
	 {
	   rates='3';
	   r.rate=rates;
	 }
       else if(rate4==1)
	 {
	   rates='4';
	   r.rate=rates;
	 }
       else if(rate5==1)
	 {
	   rates='5';
	   r.rate=rates;
	 }
       o<<endl;
       o.write((char *)&r, sizeof(ratings));//writing the
					    //ratings to file
       o.close();
       exit(0);  //exiting the program finally !
    }
  };         //end of 1st parent/base class
class front2:front_end // defining derived class
    {

      public:


      void searchResults()  //showing the search results
      {
	 cleardevice();

	 int x=getmaxx()/2;
	 int y=getmaxy()/2;

	 settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
	 //calling all the functions
	 search_Window();
	 search_Box();
	 iconSmall();

	 setcolor(56);
	 setcolor(1);

	 search_Area();

	 setcolor(DARKGRAY);

	 outtextxy(x-290,y-210,str2);

	 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	 underThe_Box();
	 loading_Line();

	 setlinestyle(SOLID_LINE,0,1);
	 delay(1000);
	 cleardevice();

	 settextstyle(DEFAULT_FONT, HORIZ_DIR,1);

	 iconSmall();
	 search_Box();
	 search_Area();
	 search_Window();

	 settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
	 outtextxy(x-290,y-210,str);

	 settextstyle(DEFAULT_FONT, HORIZ_DIR,1);

	 underThe_Box();

	 if(flag==1) // if word found
	 {
	     outtextxy(x-290,y-110,str2);
	     outtextxy(x-220,y-110,"FOUND IN FILE:");
	     outtextxy(x-100,y-110,file1);
	     files_Available();

	 }
	 else if(flag==2)
	 {
	     outtextxy(x-290,y-110,str2);
	     outtextxy(x-220,y-110,"FOUND IN FILE:");
	     outtextxy(x-100,y-110,file2);
	     files_Available();
	 }
	 else if(flag==3)
	 {
	     outtextxy(x-290,y-110,str2);
	     outtextxy(x-220,y-110,"FOUND IN FILE:");
	     outtextxy(x-100,y-110,file3);
	     files_Available();
	 }
	 else if(flag==4)
	 {
	     outtextxy(x-290,y-110,str2);
	     outtextxy(x-220,y-110,"FOUND IN FILE:");
	     outtextxy(x-100,y-110,file4);
	     files_Available();
	 }
   getch();
    }
      void NoSearchResults() // if word not found in any file
      {
	 cleardevice();

	 int x=getmaxx()/2;
	 int y=getmaxy()/2;

	 settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
	 setcolor(56);
	 setbkcolor(WHITE);

	 search_Window();
	 search_Box();
	 iconSmall();

	 setcolor(56);
	 setcolor(1);

	 search_Area();
	 underThe_Box();
	 loading_Line();

	 outtextxy(x-290,y-210,str);
	 settextstyle(SMALL_FONT, HORIZ_DIR,15);
	 outtextxy(x-100,y-110,"ERROR 404 !"); //give error

	 settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
	 outtextxy(x-100,y-50,"Nothing found in any file !");//show
							     //info
	 files_Available();
	 getch();
      }
    };          //end of derived class
class back_end //defining 2nd parent/base class
{
    public:

    front2 f2; //declaring derived class object for further use

    void inputBox()// getting the input from the user
    {
       int x=getmaxx()/2;
       int y=getmaxy()/2;

       textbackground(BLACK);
       gotoxy(5,16);
       setcolor(56);

       cin>>str;
    }
    void search() //search function
    {
       ifstream i;
       i.open(file1); //opening file 1
       i.seekg(0);

       while(!i.eof())
       {
	  i>>str2;
	  if(stricmp(str2,str)==0) //search algorithm
	   {

	     cleardevice();
	     flag=1;
	     f2.searchResults(); //show results if found
	   }
	  else{

	     cleardevice();
	     search2();//if not found in 1st file continue to 2nd

	      }
       }
    }
    void search2()
    {
       ifstream i;
       i.open(file2);
       i.seekg(0);

       while(!i.eof())
       {
	 i>>str2;

	 if(stricmp(str2,str)==0)
	 {
	    cleardevice();
	    flag=2;
	    f2.searchResults();
	 }
	 else
	 {
	    cleardevice();
	    search3();
	 }
       }
    }
    void search3()
    {

      ifstream i;
      i.open(file3);
      i.seekg(0);

      while(!i.eof())
      {
	i>>str2;

	if(stricmp(str2,str)==0)
	{
	    cleardevice();
	    flag=3;
	    f2.searchResults();
	}
	else
	{
	    cleardevice();
	    search4();
	}
      }
    }
    void search4()
    {

      ifstream i;
      i.open(file4);
      i.seekg(0);

      while(!i.eof())
      {
	i>>str2;

	if(stricmp(str2,str)==0)
	{
	    cleardevice();
	    flag=4;
	    f2.searchResults();
	}
	else
	{
	    cleardevice();
	    noFlag=1;
	    f2.NoSearchResults();
	}
      }
    }
};           // end of 2nd class

    void main()  //main
    {
    clrscr();
    //password(); //calling password function from password.h header file
    front_end f; // making all the objects
    front2 f2;
    back_end b;
    int color; //color for the image
    int gd , gm ;
    gd = VGA ; gm = VGAHI;   // initialization of VGA graphics driver

    initgraph(&gd,&gm,"c:\\turboc3\\bgi"); // bgi/graphics folder
    //f.pixel(170,50,"pic3.bmp"); // Enter File Name Here
    delay(3000);
    cleardevice();
    closegraph(); // closing vga graphics driver to initialize EGA/CGA
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
    //f.intro();
    setbkcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
    f.main_SearchBox();
    f.showmouseptr();
    f.icon();
    f.main_Symbol();

    b.inputBox();
    b.search();
    f.outro();
    cleardevice();    //clean-up//
    getch();
    }