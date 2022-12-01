#include <iostream>
#include <string>
#include <array>


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
  protected:
	std::string * frame;
  public:
	int area()
          {return width*height;}
 	void printFrame ();
//	void saveFrame(std::string& arg[][]) { frame = 

};


void Rectangle::printFrame ()
{
	std::string str[width][height];
	for ( int i=0;i<width;i++){
		for ( int j=0;j<height;j++) {
			if ((i ==0 || i==(width-1)) &&
			   (j==0 || j==(height-1))) 
			  { std::cout << "+"; str[i][j] ="+"; frame[i] = "s";}
			
			else if (i ==0 || i==(width-1) && j!=0) { std::cout << "-"; str[i][j] ="-";}

			else if ((i != 0 || i!=(width-1)) &&
					 (j == 0 || j == (height-1)))
			{std::cout << "|"; str[i][j]= "|";}
			else {std::cout << " "; str[i][j]= " ";}			



			
//			std::cout << j;
//			std::cout << " ";	
		}
		std::cout << '\n';
    }
}



class Triangle: public Polygon { 
  public:
	int area()
	  {return (width*height/2);}
};


int main () {
	
	Rectangle rtg;
	rtg.set_value(15, 20);
	rtg.printFrame();
	


	
	return 0;

}


