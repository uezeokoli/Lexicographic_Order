// /****************************************************************************************
// *  Ugonna Ezeokoli
// *  ListTest.c
// *  Test client for List ADT
// *****************************************************************************************/


#include "List.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"
void AccessFunctions() {
   List L = newList();

   //test length
   assert(length(L)==0);
   append(L,1);
   append(L,2);
   append(L,3);
   assert(length(L)==3);
   deleteFront(L);
   assert(length(L)==2);
   freeList(&L);
   printf("length() works!\n");  
   //test index
   L = newList();
   assert(index(L)==-1);
   append(L,2);
   append(L,5);
   moveBack(L);
   assert(index(L)==1);
   moveFront(L);
   assert(index(L)==0);
   deleteFront(L);
   assert(index(L)==-1);
   freeList(&L);
   printf("index() works!\n");
   //test front
   L = newList();
   append(L,1);
   append(L,4);
   assert(front(L)==1);
   prepend(L,5);
   assert(front(L)==5);
   freeList(&L);
   printf("front() works!\n");
   //test back
   L = newList();
   append(L,2);
   append(L,7);
   assert(back(L)==7);
   append(L,13);
   assert(back(L)==13);
   freeList(&L);
   printf("back() works!\n");
   //test get
   L = newList();
   append(L,3);
   append(L,5);
   append(L,7);
   moveFront(L);
   assert(get(L)==3);
   moveNext(L);
   assert(get(L)==5);
   freeList(&L);
   printf("get() works!\n");
   //test equals
   L = newList();
   List M = newList();
   append(L,1);
   append(L,2);
   append(M,1);
   assert(equals(L,M) == false);
   append(M,2);
   assert(equals(L,M) == true);
   freeList(&L);
   freeList(&M);
   printf("equals() works!\n");
}
void ManipulationFunctions() {
   //test clear
   List L = newList();
   append(L,2);
   append(L,4);
   append(L,5);
   moveBack(L);
   assert(length(L)==3);
   assert(index(L)==2);
   clear(L);
   assert(length(L)==0);
   assert(index(L)==-1);
   freeList(&L);
   printf("clear() works!\n");
   //test set
   L = newList();
   append(L,3);
   append(L,5);
   moveBack(L);
   assert(get(L)==5);
   set(L,22);
   assert(get(L)==22);
   freeList(&L);
   printf("set() works!\n");
   //test moveFront
   L = newList();
   append(L,2);
   append(L,7);
   assert(index(L)==-1);
   moveFront(L);
   assert(index(L)==0);
   assert(get(L)==2);
   moveFront(L);
   assert(index(L)==0);
   assert(get(L)==2);
   freeList(&L);
   printf("moveFront() works!\n");
   //test moveBack
   L = newList();
   append(L,2);
   append(L,7);
   assert(index(L)==-1);
   moveBack(L);
   assert(index(L)==1);
   assert(get(L)==7);
   moveBack(L);
   assert(index(L)==1);
   assert(get(L)==7);
   freeList(&L);
   printf("moveBack() works!\n");
   //test movePrev
   L = newList();
   append(L,2);
   append(L,6);
   moveBack(L);
   assert(index(L)==1);
   movePrev(L);
   assert(index(L)==0);
   movePrev(L);
   assert(index(L)==-1);
   freeList(&L);
   printf("movePrev() works!\n");
   //test moveNext
   L = newList();
   append(L,2);
   append(L,6);
   moveFront(L);
   assert(index(L)==0);
   moveNext(L);
   assert(index(L)==1);
   moveNext(L);
   assert(index(L)==-1);
   freeList(&L);
   printf("moveNext() works!\n");
   //test prepend
   L = newList();
   append(L,2);
   moveFront(L);
   assert(index(L)==0);
   prepend(L,6);
   assert(index(L)==1);
   assert(front(L)==6);
   freeList(&L);
   printf("prepend() works!\n");
   //test append
   L = newList();
   append(L,2);
   moveFront(L);
   append(L,6);
   assert(back(L)==6);
   assert(length(L)==2);
   freeList(&L);
   printf("append() works!\n");
   //test insertBefore
   L = newList();
   append(L,2);
   moveFront(L);
   insertBefore(L,6);
   movePrev(L);
   assert(get(L)==6);
   assert(length(L)==2);
   freeList(&L);
   printf("insertBefore() works!\n");
   //test insertAfter
   L = newList();
   append(L,2);
   moveFront(L);
   insertAfter(L,6);
   moveNext(L);
   assert(get(L)==6);
   assert(length(L)==2);
   freeList(&L);
   printf("insertAfter() works!\n");
   //test deleteFront
   L = newList();
   append(L,2);
   append(L,5);
   append(L,8);
   moveFront(L);
   assert(length(L)==3);
   assert(front(L)==2);
   assert(index(L)==0);
   deleteFront(L);
   assert(length(L)==2);
   assert(front(L)==5);
   assert(index(L)==-1);
   freeList(&L);
   printf("deleteFront() works!\n");
   //test deleteBack
   L = newList();
   append(L,2);
   append(L,5);
   append(L,8);
   moveBack(L);
   assert(length(L)==3);
   assert(back(L)==8);
   assert(index(L)==2);
   deleteBack(L);
   assert(length(L)==2);
   assert(back(L)==5);
   assert(index(L)==-1);
   freeList(&L);
   printf("deleteBack() works!\n");
   //test delete
   L = newList();
   append(L,2);
   append(L,3);
   append(L,7);
   moveFront(L);
   moveNext(L);
   assert(front(L)==2);
   assert(back(L)==7);
   assert(index(L)==1);
   assert(length(L)==3);
   delete(L);
   assert(front(L)==2);
   assert(back(L)==7);
   assert(index(L)==-1);
   assert(length(L)==2);
   freeList(&L);
   printf("delete() works!\n");

}


void OtherFunctions(){
   //test copylist
   List L = newList();
   
   append(L, 1);
   append(L, 2);
   append(L, 3);
   append(L, 4);

   List M = copyList(L);
   assert(equals(L,M)==true);
   assert(L!=M);
   printf("copyList() passes!\n");
   freeList(&L);
   freeList(&M);
}

int main() {

   AccessFunctions();

   ManipulationFunctions();
   
   OtherFunctions();

   printf("All tests pass!\n");

   return 0;
}
