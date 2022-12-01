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
    int default_x = 64; 
    int default_y = 16;
    string default_frame;
  protected:
    string frame;
  public:
    Rectangle ();
	int area()
          {return width*height;}
	string get_frame ();
 	void printFrame (const string&);
};

Rectangle::Rectangle()
{
    for (int i=0;i<default_y;i++){
        for (int j=0;j<default_x;j++){
            if ((i ==0 || i==(default_y-1)) &&
			   (j==0 || j==(default_x-1))) 
			  { default_frame +="+";}
			
			else if (i ==0 || i==(default_y-1) && j!=0) 
                { default_frame +="-";}

			else if ((i != 0 || i!=(default_y-1)) &&
					 (j == 0 || j == (default_x-1)))
			    {default_frame+= "|";}
			else {default_frame+= " ";}
    
        }
        default_frame+= "\n";
    } 
}

string Rectangle::get_frame()
{

	for ( int i=0;i<width;i++){
		for ( int j=0;j<height;j++) {
			if ((i ==0 || i==(width-1)) &&
			   (j==0 || j==(height-1))) 
			  { frame +="+";}
			
			else if (i ==0 || i==(width-1) && j!=0) 
                { frame+="--";}

			else if ((i != 0 || i!=(width-1)) &&
					 (j == 0 || j == (height-1)))
			    {frame+= "|";}
			else {frame+= "  ";}			
			
		}
		frame+= "\n";
    }
	return frame;
}

void Rectangle::printFrame (const string& str)
{
	for (const char c : str){
		std::cout << c;
	}	
}


class Triangle: public Polygon { 
  public:
	int area()
	  {return (width*height/2);}
};


int main () {
	
	Rectangle rtg;
	rtg.set_value(25, 25);
	rtg.printFrame(rtg.get_frame());

	
	return 0;

}


