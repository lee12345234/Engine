#include "Log.h"
void test(){
	LOG(ERROR)<<"ok";

}

int main(){
	LOG(ERROR)<<"liyingtai";
	LOG(ERROR)<<"laoli";
	LOG(INFO)<<"info:";
	LOG(WARNING)<<"warning";
	test();
	std::cout<<__FUNCTION__<<std::endl;
}
