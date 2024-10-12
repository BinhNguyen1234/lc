
#include "../include/841.h"
#include <queue>
#include <unordered_set>


bool canVisitAllRooms(vector<vector<int> > &rooms){
  
  queue<int> q;
  unordered_set<int> listRoomVisited; 
  q.push(0);

  while(!q.empty()){
    int roomCurrent = q.front();
    listRoomVisited.insert(roomCurrent);
    q.pop();
    for(int room : rooms[roomCurrent]){
      if(listRoomVisited.find(room) == listRoomVisited.end()){
	q.push(room);
      }
    }
  }


  return listRoomVisited.size() == rooms.size();
}
