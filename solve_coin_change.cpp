/*
How many ways can you make change with coins and a total amount
*/

int solve_coin_change(vector<int>& denominations, int amount) {
  // TODO: Write - Your - Code
  vector<int> solution(amount+1);
  solution[0] = 1;
  //for each denomination
  for(int den:denominations){
    //starting with the amount of that demonination, up to the amount input
    for(int i = den; i < amount + 1; i++){
        //for each ammount, add the number of sub-combinations for the amount minus the denomination
        solution[i] += solution[i-den];
    }
  }
  return solution.back();
}