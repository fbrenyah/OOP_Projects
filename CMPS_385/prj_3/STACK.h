//------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Professor	Ray Ahmadnia
//		Date		Sep. 22th, 2012
//-----------------------------------------------------------------------
#ifndef	STACK_H
#define STACK_H
template <class TYPE, int n>
class STACK{
private: TYPE a[n]; int counter;
public:	void MakeStack(){ counter=0; }
		bool FullStack(){ return( counter==(n) )? true:false; }
		bool EmptyStack(){ return( counter==0 )? true:false; }
		void PushStack(TYPE x){ a[counter]=x; counter++; }
		TYPE PopStack(){ counter--; return a[counter]; }
};
#endif
//-----------------------------------------------------------------------