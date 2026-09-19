#include<iostream>
#include<memory>
#include<unordered_map>

struct Kv{
    int key;
    int value;
    size_t mem;
    Kv(){
        key=0;

        value=0;
         mem= sizeof(key)+sizeof(value);
    }
};
int main(){
    std::unordered_map<int ,Kv>kv_cache;
    char ch;
    do{
    std::cout<<"enter the choice of the action you want to perform 1.For New Value insert ,2.For check the size of the kv cache buffer ,3.Retrieval of Id's"<<std::endl;

    std::cin>>ch;


    switch (ch) {
        case '1':{
        Kv kv;
        std::cout<<"Enter the key and value u want to insert"<<std::endl;
        std::cin>>kv.key>>kv.value;
        kv_cache.insert({kv.key,kv});
        break;
        }
        case '2':{
            Kv kv;
        std::cout<<"the size of kv cache object is"<<sizeof(Kv)<<std::endl;
    break;
        }
    case '3':{
        Kv kv;
    std::cout<<"Enter the key u want to retrieve"<<std::endl;
    int key;
    std::cin>>key;
    auto i=kv_cache.find(key);
    if(i!=kv_cache.end()){
        std::cout<<"the value of the key is"<<i->second.value<<std::endl;
        std::cout<<"And also the memory size of the key value pair is"<<i->second.mem<<std::endl;
    }
else {
    std::cout<<"the key is not present in the kv cache"<<std::endl;
}
break;
    }
case '4':{
    Kv kv;
int key;
std::cout<<"enter the key u wanna delete"<<std::endl;
std::cin>>key;
auto i=kv_cache.find(key);
if(i!=kv_cache.end()){
    kv_cache.erase(i);
    std::cout<<"the key value pair is deleted"<<std::endl;

}
else {
    std::cout<<"the key is not present in the kv cache"<<std::endl;
    
}
break;

 
 } 
     } 
    }while(ch!='0');
 return 0;

}

