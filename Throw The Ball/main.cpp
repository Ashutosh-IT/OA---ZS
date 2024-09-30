/*

In a park there are n friends standing in a random order, and they plan to throw a ball around.
Each friend has a unique number in the range of 1 to n, inclusive. 
The ith friend will always throw the ball towards the friend given at receiver[i], and this will happen each second.
Friend 1 always starts with the ball, and a player always throw to another player.
Determine which friend has the ball after k seconds pass.

Note: Friends are numbered starting with 1.

Example :
receiver = [2,4,1,5,3]
seconds = 6

Output : 2

*/


int throwTheBall(vector<int>receiver, long seconds){
  int n = receiver.size();
  
  unordered_map<int,int> mp;
  int curr = 1;
  long time = 0;
  
  while(true){
    if(time == seconds)
    return curr;
    
    if(mp.find(curr) != mp.end())
    break;
    
    mp[curr] = time;
    curr = receiver[curr-1];
    time++;
  }
  
  int loop = time-mp[curr];
  seconds -= time;
  seconds %= loop;
  
  for(int i=0; i<seconds; i++)
  curr = receiver[curr-1];
  
  return curr;
}
