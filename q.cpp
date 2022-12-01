#include "q.h" 


using std::string;

class Polygon {
  protected:
	int width, height;
	
  public:

	void set_value (int a, int b) 
	  {width=a, height=b;}
	virtual int area () =0;
	
	void printarea () 
	  {std::cout << this->area() << std::endl;}

};


class Rectangle: public Polygon {
    int default_x; 
    int default_y;
    string default_frame;
  protected:
    string frame;
  public:
    Rectangle ();
	int area()
          {return width*height;}
	void spaceFrame ();
 	void printFrame ();
};

Rectangle::Rectangle()
{
    default_x = 64;
    default_y = 16;
    for (int i=0;i<default_y;i++){
        for (int j=0;j<default_x;j++){
            if ((i ==0 || i==(default_y-1)) &&
			   (j==0 || j==(default_x-1))) 
			  { std::cout << "+"; default_frame +="+";}
			
			else if (i ==0 || i==(default_y-1) && j!=0) 
                { std::cout << "-"; default_frame +="-";}

			else if ((i != 0 || i!=(default_y-1)) &&
					 (j == 0 || j == (default_x-1)))
			    {std::cout << "|"; default_frame+= "|";}
			else {std::cout << " ";default_frame+= " ";}
    
        }
        default_frame+= "\0";
        std::cout<<'\n';
    } 

}

void Rectangle::spaceFrame()
{

	std::string str[width][height];
	for ( int i=0;i<width;i++){
		for ( int j=0;j<height;j++) {
			if ((i ==0 || i==(width-1)) &&
			   (j==0 || j==(height-1))) 
			  { std::cout << "+"; str[i][j] ="+";}
			
			else if (i ==0 || i==(width-1) && j!=0) 
                { std::cout << "-"; str[i][j] ="-";}

			else if ((i != 0 || i!=(width-1)) &&
					 (j == 0 || j == (height-1)))
			    {std::cout << "|"; str[i][j]= "|";}
			else {std::cout << " "; str[i][j]= " ";}			
			
		}
		std::cout << '\n';
    }
}

void Rectangle::printFrame ()
{
	spaceFrame();
}


class Triangle: public Polygon { 
  public:
	int area()
	  {return (width*height/2);}
};


int main () {
	
	Rectangle rtg;
	rtg.set_value(15, 20);
//	rtg.printFrame();

	
	return 0;

}


