// ************** FENWICK TREE ********************
class FenwickTree
  {
    std::vector<int> store;
    std::vector<int> v;
    int n ;
  public:
   FenwickTree(std::vector<int> &vec){
      store = vec;

      n = store.size();
      v.resize(n);
      // cout<<"size of the array is : "<<n<<"\n";
      initialize();
    }

  void initialize(){
    // cout<<"creating the initial tree \n";
    for(int i=0;i<n;i++){
      update(i,store[i]);
    }
    // cout<<"printing the tree \n";
    // printTree();
  }

  void printTree(){
      for (int i = 0; i <=n; ++i)
      {
        cout<<v[i]<<" ";
      }
      cout<<"\n";
    }

  void update(int pos,int val){
      pos++;
      while(pos <= n){
        v[pos] += val;
        pos += (pos)&(-pos);
      }
    }

  int query(int pos){
      // pos;
      int res = 0;
      while( pos>0){
        res+= v[pos];
        pos -= (pos) & (-pos);
      }
    return res;
    }


public:
  FenwickTree();
  // ~FenwickTree();
  
};