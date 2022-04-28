#ifndef LRUCACHE_HPP_
#define LRUCACHE_HPP_

#include<iostream>
#include<list>
#include<map>
#include<unordered_map>

using namespace std;


namespace lrucachedef{

class LRUCache{

public:

LRUCache(int capacity): n(capacity){}

int get(int key) {
    if(mp.find(key)!=mp.end()){
        searchCache(key,mp[key]->second); 
        return mp[key]->second;
    }else{
        return -1;
    }
}

void put(int key, int val){
    if(mp.find(key)!=mp.end()){
       searchCache(key,val); 
    }else{
        if (cache.size()<n){
            cache.push_front({key,val});
            mp[key]=cache.begin();
        }else{
            mp.erase(cache.back().first);
            cache.pop_back();
            cache.push_front({key,val});
            mp[key]=cache.begin();
        }
    }
}

private:

int n;
list<pair<int,int>> cache;
unordered_map<int,list<pair<int,int>>::iterator> mp;

void searchCache(int key,int val){
    if(mp.find(key)!=mp.end()){
        cache.erase(mp[key]);
        cache.push_front({key,val});
        mp[key]=cache.begin();
    }
}

};

}

#endif