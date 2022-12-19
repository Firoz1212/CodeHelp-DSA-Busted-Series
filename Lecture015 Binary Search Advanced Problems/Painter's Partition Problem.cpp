bool MinimumTimePossible(vector<int> &boards, int k, int mid) 
{    
    int painter=1;   
    int area=0;   
    for(int i=0; i<boards.size(); i++) 
    {             
        if(area+ boards[i]<= mid)       
        {          
            area = area + boards[i];       
        }                 
        else        
        {            
            painter++;                       
            if(painter>k || boards[i]> mid)            
            {               
                return false;             
            }                        
            area = boards[i];         
        }                
        if(painter>k)        
        {            
            return false;        
        }          
    } 
    return true; 
}

int findLargestMinDistance(vector<int> &boards, int k) 
{  int s = 0;   
 int sum = 0;   
 int ans = -1;   
 for(int i=0; i<boards.size(); i++){    
     sum = boards[i] + sum;  
 }   
 int end= sum;  
 int mid= s + (end-s)/2;   
 while(s<=end) 
 {      
     if(MinimumTimePossible(boards, k, mid))  
     {          
         ans = mid;          
         end = mid-1;       
     }               
     else     
     {         
         s = mid+1;     
     }      
     mid = s + (end-s)/2;    
 } 
 return ans;
}
