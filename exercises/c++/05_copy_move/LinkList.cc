#include<memory>
#include<iostream>
#include<algorithm>
#include<utility>

#include "ap_error.h"


enum class Insertion_method { push_back, push_front };

template <class value_type>
class List {
 public:
  List() noexcept = default;
  List(List&& l) noexcept = default;
  List& operator=(List&& l) noexcept = default;

  List(const List& l);
  List& operator=(const List& l);
  
  // insert a new node with the value v according to the method m
  // this method should be used to fill the list
  template <class OT>
  void insert(OT&& v, const Insertion_method m);


  template <class O>
  friend std::ostream& operator<<(std::ostream&, const List<O>&);
  
  /*void insert(const value_type& v, const Insertion_method m){

	if(int(m)==0) {push_back(v);}
	else if(int(m)==1) {push_front(v);}
	}*/

  // return the size of the list
  std::size_t sizelist() const;

  // delete all the nodes of the list
  void reset();


 private:
 
  // private struct node with the proper value_type
  struct node {
    value_type value;
    std::unique_ptr<node> next;

    // implement suitable constructor(s) for node
    node(const value_type& v, node* p) : next{p}, value{v} {
      std::cout << "copy ctor" << std::endl;
    }

    node(value_type&& v, node* p) : next{p}, value{std::move(v)} {
      std::cout << "move ctor" << std::endl;
    }

    explicit node(const std::unique_ptr<node>& p) : value{p->value} {
      if (p->next)
	next = std::make_unique<node>(p->next);
    }
  


    // copy and move semantics if needed
    
    // destructor
	~node(){}
  };

  // append the newly created node at the end of the list
/* void push_back(const value_type& v){
	std::unique_ptr<node> new_node=new node();
	new_node->value=v;
	new_node->next=nullptr;

	node* tmp=head.get();
	while(tmp->next){
		tmp=tmp->next.get();
	}

	tmp->next=new_node.get();
	size+=1;
	}*/
  template <class OT>
  void push_back(OT&& v) {
    node* last = tail();
    last -> next = std::make_unique<node>(std::forward<OT>(v), nullptr);
  }
  // insert the newly created node in front of the list


  template <class OT>
  void push_front(OT&& v) {
    // auto h = head.release();
    // auto new_node = new node {v,h};
    //head.reset(new_node);

    head = std::make_unique<node>(std::forward<OT>(v), head.release());
  }
  
  /* void push_front(const value_type& v){
	std::unique_ptr<node> new_node=new node();
	new_node->next=head.release();
	head=new_node.get();
	size+=1;

        
          head = std::make_unique<node>(v,head,release());
	  }*/

  node* tail() noexcept{
	auto tmp = head.get();
	while(tmp->next){
		tmp=tmp->next.get();
	}
	return tmp;
  }

  //node* tail() noexcept;


  std::unique_ptr<node> head;
  std::size_t size;
};


template <class T>
template <class OT>
void List<T>::insert(OT&& v, const Insertion_method m) {
	if(!head){
	  //head.reset(new node{v,nullptr});
	  head = std::make_unique<node>(std::forward<OT>(v), nullptr);
		return;
	}
	
	switch(m){
	case Insertion_method::push_back:
	   push_back(std::forward<OT>(v));
	   break;
	
	case Insertion_method::push_front:
	   push_front(std::forward<OT>(v));
	   break;

	default:
	  AP_ERROR(false) << "Unknown insertion method";
	  break;
	};
}


/*template <class T>
tepmlate <class OT>
void List<T>::push_back(OT&& v){
	node* last=tail();
	last->next =std::make_unique<node>{std::forward<OT>(v),nullptr};*/

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l){
	auto tmp = l.head.get();
	while(tmp){
		os << tmp->value << " ";
		tmp=tmp->next.get();
	}
	return os;
}

template <class T>
List<T>::List(const List& l) {
  head = std::make_unique<node>(l.head);
}



int main() {
	try{
	  List<int> l{};

	  l.insert(4, Insertion_method::push_back);
	  l.insert(5, Insertion_method::push_back);
	  l.insert(3, Insertion_method::push_front);

	  std::cout<<l<<std::endl;

	  auto ol = l;
	  int a = 9;
	  l.insert(14, Insertion_method::push_front);
	  l.insert(a, Insertion_method::push_front);

	  std::cout << l << std::endl;
	  std::cout << ol << std::endl;

	} catch (std::exception& e) {
	  std::cerr << e.what() << std::endl;
	
	} catch(...) {
	  std::cerr << "Unknown exception" << std::endl;
	}
	return 0;
 }
