#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct node;
typedef struct node *PtrToNode;

struct node
{
       int element;
       PtrToNode next;
       };
                                   // Make Empty //
PtrToNode MakeEmpty(PtrToNode L)
{
          L=new struct node;
          if(L==NULL)
                     printf("Out of Memory :( ");
                     L->next=NULL;
                     return L;
}
                   
                        //************* InsertLast *************//
void InsertLast(int i,PtrToNode L)
{
     if(L != NULL)
     {
      PtrToNode TmpCell=new struct node;
      TmpCell->element=i;
      PtrToNode P=L;
      while(P->next!=NULL)
      { 
        P=P->next;
        }
        P->next=TmpCell;
        TmpCell->next=NULL;
      }
}
                        
                        //********** Join ********** //
void Join(PtrToNode L)
{
     PtrToNode P=L;
     while(P->next!=NULL)
     {
       P=P->next;
     }
     P->next=L->next;
}           
                          //********** Delete ********** //
void Delete(PtrToNode Q)
{
     PtrToNode TmpCell; 
     TmpCell=Q->next;
     Q->next=TmpCell->next;
     delete(TmpCell);  
}

                   //********** Another DecreasingNodes ********** //
/*                 // has error if m = 2 or more :(
int DecreasingNodes(int m,int n,PtrToNode L){
     PtrToNode P=L; // pointer to the player
     PtrToNode Q=L; // cleaner pointer ;) 
    for(int i=0;i<n-1;i++)
     {
            
            P=P->next;   
            for(int x=0;x<m;x++)
            {
                    P=P->next;
                    Q=Q->next;
                    printf("\n Player # %d Out",P->element);
                    Delete(Q); // Deletes the node that P step on previously
             }
      }
        }
        P->next=TmpCell;
        TmpCell->next=NULL;
      }
}
                        
                        //********** Join ********** //
void Join(PtrToNode L)
{
     PtrToNode P=L;
     while(P->next!=NULL)
     {
       P=P->next;
     }
     P->next=L->next;
}           
                          //********** Delete ********** //
void Delete(PtrToNode Q)
{
     PtrToNode TmpCell; 
     TmpCell=Q->next;
     Q->next=TmpCell->next;
     delete(TmpCell);  
}

                   //********** Another DecreasingNodes ********** //
/*                 // has error if m = 2 or more :(
int DecreasingNodes(int m,int n,PtrToNode L){
     PtrToNode P=L; // pointer to the player
     PtrToNode Q=L; // cleaner pointer ;) 
    for(int i=0;i<n-1;i++)
     {
            
            P=P->next;   
            for(int x=0;x<m;x++)
            {
                    P=P->next;
                    Q=Q->next;
                    printf("\n Player # %d Out",P->element);
                    Delete(Q); // Deletes the node that P step on previously
             }
      }
       return (P->next->element);  
}*/
//********** DecreasingNodes ********** //
int DecreasingNodes(int m,int n,PtrToNode L)
{
    PtrToNode P=L;
    
    
    for(int i=0;i<n-1;i++)
    {
            PtrToNode T=P->next;       
            for(int x=0;x<m;x++)
            {
                    
                    T=T->next;
                    printf("\n Player # %d Out",T->element);
                    }
    P=T->next;
    Delete(T);
            
    }
    return (P->element);
    }
                         //********** MAIN ********** //
          
 main()
{
     int m,n; // n=number of persons , m = #of passes 
     int result;
     PtrToNode L;
     L=MakeEmpty(NULL);
                  // initiate list of Nodes
     printf("plz enter # of nodes\t");
     scanf("%d",&n);
     printf("plz enter # of Steps to Jump \t");
     scanf("%d",&m);
     
     for(int i=1;i<n+1;i++)
     {
             InsertLast(i,L);
             }    
    Join(L); // join the last node with the node after header         
    result=DecreasingNodes(m,n,L);
    printf("\n Player # %d wins",result);
    getch();
     return 0;
 }
