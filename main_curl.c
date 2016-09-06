#include<stdio.h>
#include <curl/curl.h>
#include "take_curl.c"
int main()
{
        
	take_curl("http://localhost/paring/gate.php");
//       pritnf("%s",take_curl); 
       
	return 0;
        
}
