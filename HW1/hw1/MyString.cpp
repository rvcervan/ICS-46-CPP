
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int NumAllocations = 0;
class MyString
{
	char* buf; //points to the array holding the characters in this MyString object.
	//Must be allocated in constructor and, maybe in other functions as well
	//This C-string must be null terminated and that is how you know the length
	//strlen() will count the number of characters up to the first null character
	

	//utility method to handle errors, note throws an exception to prevent
	//access to undefined values. Always call this method when you detect a fatal error from
	//any of your methods.
	//
	//
	//input output 1000
	//new and delete 1000
	//
	void error(const char* s)
	{
		cerr<<"Error: "<< s <<endl;
		throw 0;
	}

public:


	int strlen(const char* s) const //T(N) = 3N + 2
	{
		int len = 0; //1
		while(s[len] != '\0')//N*2
		{
			++len;//N*1
		}
		return len;//1
	}

	char* strcpy(char* dest,const char* src) const//T(N) = 3N + 2
	{
		char* d = dest;//1
		while (*d++ = *src++)//N*3
			;
		return dest;//1
	}

	char* strdup(const char* s)//T(N) =  3N + 1008
	{	//1    3N+2   1000    1  3N+2    1   
		return strcpy(new char[strlen(s) + 1], s);//1 + 3N + 2 + 1000 + 3N + 2 + +1 + 1
		++NumAllocations;//1
	}
	

	int strcmp( char* s1, const char* s2) const//T(N) = 23N + 10
	{
		int index = 0;//1
		while(s1[index] != '\0' && s2[index] != '\0')//N*4
		{

			if(s1[index] -  s2[index] == 0)//N*4
			{
				++index;//N*1
			}
			else if(s1[index] - s2[index] > 0)//N*4
			{
				return s1[index] - s2[index];//N*3
			}
			else if(s1[index] - s2[index] < 0)//N*4
			{
				return s1[index] - s2[index];//N*3
			}
		}
		
		if(s1[index] == '\0' && s2[index] == '\0')//4
		{
			return 0;//1
		}
		else if(s1[index] == '\0')//2
		{
			return -1;//1
		}
		else
		{
			return 1;//1
		}
	}

	char* strstr(char* s1, char* s2) const//T(N) = 6N^2 + 3N + 1
	{
		while(*s1)//N
		{
			char* Start = s1;//N
			char* Sub = s2;//N

			while(*s1 && *Sub && *s1 == *Sub)//N(N)
			{
				s1++;//N*N
				Sub++;//N*N
			}
			if(!*Sub)
			{
				return Start;//N*N
			}
			s1 = Start + 1;//N*N*2
		}
	
		return NULL;//1
			 	
	}

	char* str2dup( char* s1, char* s2)const//T(N) = 16N + 4024
	{
		
		char* first = new char[len(s1) + 1];//1003
		char* second = new char[len(s2) + 1];//1003
		++NumAllocations;//1
		++NumAllocations;//1
		char* str1 = strcpy(first, s1);//1 + 3N + 2
		char* str2 = strcpy(second, s2);//1 + 3N + 2
		
		char* temp = strcat(str1, str2);//1 + 10N + 6
		

		delete[] first;//1000
		delete[] second;//1000
		--NumAllocations;//1
		--NumAllocations;//1
		return temp;//1
		
		
	}	

	char* strcat(char* dest, const char* src) const//T(N) = 10N + 6
	{
		
		size_t a, b;
		for(a=0; dest[a] != '\0'; a++)//1 + 2*N + N
		{
			;
		}
		for(b = 0; src[b] != '\0'; b++)//1 + 2N + N
		{
			dest[a+b] = src[a];//4N
		}
		dest[a+b] = '\0';//3
		return dest;//1
		
		/*
		int size = 0;
		int s1 = len(dest);
		int s2 = strlen(src);
		char* temp = new char[s1 + s2 + 1];
		while(dest != '\0')
		{
			temp[size] = dest[size];
			size++;
		}
		int other = 0;
		while(src != '\0')
		{
			temp[size] = src[other];
			size++;
			other++;
		}
		delete[] dest;
		dest = temp;
		dest[s1+s2] = '\0';
		delete[] temp;
		return dest;
		*/

	}

	int len(char* str) const//helper for rev T(N) = 3N + 2
	{
		int size = 0;//1
		while(str[size] != '\0')//2N
		{
			++size;//N
		}
		return size;//1
	}

	char* strrev(char* str) const// T(N) = 11N + 3
	{
		int start = 0;//1
		int end = len(str)-1;//1
		
		while(start < end)//N
		{
			char temp = str[start];//3N
			str[start] = str[end];//3N
			str[end] = temp;//2N
			start++;//N
			end--;//N
		}
		return str;//1		
	}
		

	

	explicit MyString(const char* s = "")// T(N) = 3N + 1009
	//constructs this object from a c-string s (s is an array of char terminated by '\0')
	//parameter, s, defaults to the empty string ""
	//write and use strdup() to implement this constructor,
	//it allocates a new array, then uses strcpy() to copy chars from array s to the new array 
	{
		buf = strdup(s); //1 + 3N + 1008
	}

	//copy constructot for a MyString, must make a deep copy of
	//s for this. You can use strdup() you wrote
	MyString(const MyString& s)//T(N) = 3N + 1009
	{
		buf = strdup(s.buf);//1 + 3N + 1008
	}

	//assigns this MyString from MyString s, MUST DO DEEP ASSIGNMENT
	//remember, both this and s have been previously constructed
	//so they each have storage pointed to by buf
	MyString& operator=(const MyString& s)//T(N) = 3N^2 + 2010N + 2
	{
		if(buf != s.buf)//1
		{
			delete[] buf;//1000N
			--NumAllocations;//N
			buf = strdup(s.buf);//N + N(3N + 1008)
		}
		return *this;//1
	}

	//return a reference to the char at position index, 0 is the first element and so on
	//index must be in bounds (see method above)
	char& operator[](const int index)//T(N) = 1003
	{
		if(index>length())//1
		{
			cerr<<"Error " << endl;//1000
			throw 0;//1
		}
		else
		{
			return buf[index];//1
		}

	}

	int length() const//T(N) = 3N + 2
	{
		int length = 0;//1
		while(buf[length] != '\0')//2N
		{
			++length;//N
		}
		return length;//1
	}

	//return the index of the first occurance of c in this MyString
	//indices range from 0 to length()-1
	//returns -1 if the character c is not in this MyString
	int indexOf(char c) const//T(N) = 6N + 2
	{
		int index = 0;//1
		while(buf[index] != '\0')//2N
		{
			if(buf[index] == c)//2N
			{
				return index;//N
			}
			else
			{
				++index;//N
			}
		}
		return -1;//1
	}

	//returns the index of the first occurance of pat in this MyString
	//indices range from 0 to length()-1
	//returns -1 if the character string pat is not in this MyString
	//write and use strstr() to implement this function
	int indexOf(const MyString& pat)const//12N^2 + 12N + 7
	{
		

		if(strstr(buf, pat.buf)!= NULL)//6N^2 + 3N + 1 + 1
		{
			return indexOf(strstr(buf, pat.buf)[0]);//6N + 2 + 6N^2 + 3N + 1 + 1
		}
		else
		{
			return -1;//1
		}
	}

	//True if the two MyStrings contain the same chars in same position
	//e.g, "abc"=="abc" returns true
	//write and use strcmp() to implement this function
	bool operator==(const MyString& s) const//T(N) = 23N + 14
	{
		
		int result = strcmp(buf, s.buf);//1 + 23N + 10
		
		if(result == 0)//1
		{
			return 1;//1
		}
		else
		{
			return 0;//1
		}
		
		
	}

	//concatenates this and s to make a new MyString
	//e.g., "abc"+"def" returns "abcdef"
	//write and use str2dup() to implement this function, it should allocate a new
	//array then call strcpy() and strcat()
	MyString operator+(const MyString& s) const//T(N) = 16N + 4025
	{
		
		char* temp = str2dup(buf, s.buf);//1 + 16N + 4024


		return MyString(temp);//1
		 
	}

	//concatenates s onto end of this
	//e.g., s = "abc"; s+="def" now s is "abcdef"
	//use str2dup()
	MyString& operator+=(const MyString& s)//T(N) = 16N + 5028
	{
		char* temp = str2dup(buf, s.buf);//1 + 16N + 4024
		
		delete[] buf;//1000
		--NumAllocations;//1
		buf = temp;//1
		return(*this);//1
	}

	//returns another MyString that is the reverse of this MyString
	//e.g., s = "abc"; s.reverse() returns "cba"
	//write strrev(char* dest, char* src) like strcpy but copies the reverse of src into dest, then ust it
	MyString reverse() const// T(N) = 11N + 3
	{
		return MyString(strrev(buf));//11N+3
	}

	//prints out this MyString to the ostream out
	void print(ostream& out) const//T(N) = 1000
	{
		out << buf;//1000
	}

	//reads a word from the istream in and this MyString
	//becomes the same as the characters in that word
	//use getline() to implement read()
	void read(istream& in)// T(N) = 3N + 3010
	{
		char local[1024];//1
		in.getline(local, 1024);//1000
		delete[] buf;///1000
		--NumAllocations;//1
		buf = strdup(local);//1 + 3N + 1008 
	
	}

	//destruct a MyString, must free up any storage allocated within MyString
	~MyString()//T(N) = 1001
	{
		
		delete[] buf;//1000
		--NumAllocations;//1
	}
};

//these two I/O methods are complete as long as you define print and read methods correctly
inline ostream& operator<<(ostream& out, const MyString& str)//1001
{
	str.print(out);//1000 assuming
	return out;//1
}

inline istream& operator>>(istream& in, MyString& str)//1001
{
	str.read(in);//1000 assuming
	return in;//1
}

//TBD: Write all these testing functions and add more of your own
//follow my example and write a function to test each method.
//Name each of these functions so they clearly indicate what they are testing


MyString copyConstructorTest(MyString l)//T(N) = 1
{
	return l;//1
}

void testReverse()//works T(N) = 11N + 5003
{
	cout << "MyString s('hello there')" << endl;//1000
	cout << "s.reverse() expected output: ereht olleh" << endl;//1000
	MyString s("hello there");//1000
	cout <<"result: " <<  s.reverse() << endl;//1000 + 11N + 3
	cout << endl;//1000
}
void testPattern()//works T(N) = 24N^2 + 24N + 9014
{
	//1000
	MyString s("My Name is Buf");//1000
	
	MyString d("Name");//1000
	MyString h("Hello");//1000
	cout << "MyString s('My Name is buf')" << endl;//1000
	cout << "MyString d('Name')" << endl;//1000
	cout << "MyString h('Hello')" << endl;//1000
	cout << "Using s.indexOf(d) expected output: 3" << endl;//1000
	cout<<"result: "  << s.indexOf(d) << endl;//1000 + 12N^2 + 12N + 7
	cout << "Using s.indexOf(h) expected output: -1" << endl;//1000
	cout <<"result: " << s.indexOf(h) << endl;//1000 + 12N^2 + 12N + 7
	cout << endl;//1000
}

void testPlus()//doesnt work T(N) = 16N + 11025
{
	MyString s("Hello");//1000
	MyString d("There");//1000
	cout << "MyString s('Hello')" << endl;//1000
	cout << "MyString d('There')" << endl;//1000

	cout << "Using s+d; expected: 'Hello There'" << endl;//1000
	cout<< "result: "  << s+d << endl;//1000 + 16N + 4025
	cout << endl;//1000
}

void testPlusEquals()//doesnt work T(N) = 16N + 12028
{
	MyString s("Hello");//1000
	MyString d("There");//1000
	cout << "MyString s('Hello')" << endl;//1000
	cout << "MyString d('There')" << endl;//1000
	cout << "using s+=d; expected from s: Hello There" << endl;//1000
	s += d;//16N + 5028
	cout << "result: " << s << endl;//1000
	cout << endl;//1000
}
void testCompare()//works T(N) = 46N + 15028
{
	MyString s("hello");//1000
	MyString h("hello");//1000
	MyString v("howdy");//1000
	
	cout << "MYString s('hello')" << endl;//1000
	cout << "MyString h('hello')" << endl;//1000
	cout << "MyString v('howdy')" << endl;//1000
	cout << "Comparing between 'hello'(s) and 'hello'(h)" << endl;//1000
	cout << "s==h; expected: True" << endl;//1000
	if(s==h)//23N + 14
	{
		cout << "result: True" << endl;//1000
	}
	else
	{
		cout << "result: False" << endl;//1000
	}
	
	cout << "Comparing between 'hello'(s) and 'howdy'(v)" << endl;//1000
	cout << "s==v; expected: False" << endl;//1000
	if(s==v)//23N + 14
	{
		cout << "result: True" << endl;//1000
	}
	else
	{
		cout << "result: False" << endl;//1000
	}
	cout << endl;//1000
}

void testInput()//works T(N) = 6000
{
	MyString s;//1000
	cout << "MyString s;" << endl;//1000
	cout << "cin>>s; expected user input" << endl;//1000
	cin >> s;//1000
	cout <<"result: " <<  s << endl;//1000
	cout << endl;//1000
}

void testPrint()//works T(N) = 5000
{
	MyString s("hello");//1000
	cout << "MyString s('hello')" << endl;//1000
	cout << "cout<<s; expected: 'hello'" << endl;//1000
	cout << "result: " << s << endl;//1000
	cout << endl;//1000
}

void testAssignment()//works T(N) = 3N^2 + 2010N + 9002
{
	MyString s("Hello");//1000
	MyString h("Goodbye");//1000
	cout << "MyString s('Hello')" << endl;//1000
	cout << "MyString h('Goodbye')" << endl;//1000
	cout <<"cout<<s; expected: 'Hello'" << endl;//1000
	cout <<"result: " <<  s << endl;//1000
	cout << "After assignment using s=h; expected: 'Goodbye'" << endl;//1000
	s = h;//3N^2 + 2010N + 2
	cout << "result: " << s << endl;//1000
	cout << endl;//1000
}


void testLength()//works T(N) = 3N + 5002
{
	MyString s("Hello");//1000
	cout << "MyString s('Hello')" << endl;//1000
	cout << "s.length(); expected: 5" << endl;//1000
	cout << "result: " << s.length() << endl;//1000 + 3N + 2
	cout << endl;//1000
}

void testBounds()//works T(N) = 9006
{
	
	MyString s("hello");//1000
	cout << "MyString s('hello')" << endl;//1000
	cout << "using s[0]; expected: h" << endl;//1000
	cout << "result: " << s[0]  << endl;//1000 + 1003
	cout << "using s[5]; expected: " << endl;//1000
	cout <<"result: " <<  s[5] << endl;//1000 + 1003
	cout << endl;//1000
	
	
}

void testIndexOfCharacter()//Works T(N) = 6N + 5002
{
	MyString s("Hello");//1000
	cout << "MyString s('Hello')" << endl;//1000
	cout << "using s.indexOf('o'); expected: 4" << endl;//1000
	cout << "result: " << s.indexOf('o') << endl;//1000 + 6N + 2
	cout << endl;//1000
}
//write more test functions here
//...


int main()
{


	//This try/catch will catch any exception thrown by MyString::error()
	//while calling test functions.
	try
	{
		cout << "=====Testing PlusEqual=====" << endl;
		testPlusEquals();
		cout << "=====Testing Plus=====" << endl;
		testPlus();
		cout << "=====Testing Pattern=====" << endl;
		testPattern();
		cout << "=====Testing Print=====" << endl;
		testPrint();
		cout << "=====Testing indexOf Character=====" << endl;
		testIndexOfCharacter();
		
		cout << "=====Testing length=====" << endl;
		testLength();

		cout << "=====Testing reverse()=====" << endl;
		testReverse();

		cout << "=====Testing compare()=====" << endl;
		testCompare();
		cout << "=====Testing Assignment=====" << endl;
		testAssignment();
		cout << "=====Testing brackets=====" << endl;
		testBounds();
		cout << "=====Testing Input=====" << endl;
		testInput();
		//put more test function callse here written just above
	
	}
	catch(int i)
	{
	cout << "Got an exception: " << i << endl;
	}
	cerr<< "Net memory allocated at program end: " << NumAllocations << endl;
	cerr<< "(should be zero! positive = memory leak, negative = duplicate delete)\n";
	return 0;
}





