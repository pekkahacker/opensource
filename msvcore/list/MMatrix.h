/*
 * Company:	MSV (MikelSV) code name Vyris or Sumbios
 * This: MMatrix - My Matrix class
 *		 My version Array class
 */
/*
  --------------------------------------------------------------------------------

	COPYRIGHT NOTICE, DISCLAIMER, and LICENSE:

	MMatrix version 1.2.3 7/Mai/2005
	MMatrix version 1.2.5 10/August/2006
	MMatrix version 1.2.6 18/August/2006

	LMatrix	verison	1.0.0 17/02/2007

	TMatrix	version	1.0.0 19/09/2007

	UMatrix	version	1.0.0 22/09/2007

	MMatrix : Copyright (C) 2004 - 2006, Mishael Senin its XMatrix and YMatrix
	LMatrix : Copyright (C) 2007, Mishael Senin : Live Matrix
	TMatrix : Copyright (C) 2007, Mishael Senin : Titan Matrix
    UMatrix : Copyright (C) 2007, Mishael Senin : Unlimited Matrix





	Covered code is provided under this license on an "as is" basis, without warranty
	of any kind, either expressed or implied, including, without limitation, warranties
	that the covered code is free of defects, merchantable, fit for a particular purpose
	or non-infringing. The entire risk as to the quality and performance of the covered
	code is with you. Should any covered code prove defective in any respect, you (not
	the initial developer or any other contributor) assume the cost of any necessary
	servicing, repair or correction. This disclaimer of warranty constitutes an essential
	part of this license. No use of any covered code is authorized hereunder except under
	this disclaimer.

	Permission is hereby granted to use, copy, modify, and distribute this
	source code, or portions hereof, for any purpose, including commercial applications,
	freely and without fee, subject to the following restrictions: 

	1. The origin of this software must not be misrepresented; you must not
	claim that you wrote the original software. If you use this software
	in a product, an acknowledgment in the product documentation would be
	appreciated but is not required.

	2. Altered source versions must be plainly marked as such, and must not be
	misrepresented as being the original software.

	3. This notice may not be removed or altered from any source distribution.

  --------------------------------------------------------------------------------


  --------------------------------------------------------------------------------
 */

#define		MMATRIX_VER "1.3.6"

class MMatrixXD{
public:
	//virtual void destroy(void*){};
	virtual ~MMatrixXD(){};
};

struct MMatrixD;

struct MMatrixR: public MMatrixXD{
MMatrixD *_a, *_e;
int _sz;
};

struct MMatrixD: public MMatrixXD{
MMatrixD *_p, *_n;
};


struct MMatrixX: public MMatrixXD{
public:
MMatrixX *_a, *_e, *_p, *_n;
int _sz;
};




//delete - next, prev	class delete
int _mdeletex(MMatrixX* root, MMatrixX* data, MMatrixXD*cls);

// delete all for all types		size delete all	 class delete
int _mdeleteallx(MMatrixX* root, MMatrixXD*cls);


//		MMATRIX 

// <- & ->	 DOUBLE	 <- & ->
//		-> prev next <-


// insert - prev, next
void* _minsert(MMatrixR* root, MMatrixD* data);


//delete - next, prev	automatic delete
int _mdelete(MMatrixR* root, MMatrixD* data);

//delete - next, prev	user delete
void* _mdelete_u(MMatrixR* root, MMatrixD* data);

// delete all for all types		automatic delete all
int _mdeleteall(MMatrixR* root, MMatrixD* data);

// delete all for all types		size delete all
//int _mdeleteall(MMatrixR* root, MMatrixD* data, class *clr);

// change for all types
int _change(MMatrixR* t, MMatrixD*ind, MMatrixD*tind);

void* _minsertx(MMatrixX* root, MMatrixX* data);
int _mdeletex(MMatrixX* root, MMatrixX* data);
int _mdeleteallx(MMatrixX* root, MMatrixX* data);

//int _mdeleteallcx(MMatrixX* root, class* data);

inline unsigned int vti(void* v){
unsigned int r; memcpy(&r, &v, 4);
return r;
}


/*
inline void* X_mrap(void* v, int p){
char*z=0; memcpy(z, v, 1024);
	//deleted //int a=(int)v;
//return (void*)(a+p);
return 0;
}

inline void* _mrap(void* v, int p){
char*z=0; memcpy(z, v, 4);
	//deleted //int a=(int)v;
//return (void*)(a+p);
return 0;
}*/


/*
// DELETE OF OLD FORMAT
// INSERT 

// next // prev - standart
template < class D, class M>
M* _minsert(D&t, M*m){

	if(t->sz<1){
        t->a=new M;
        t->a->p=NULL;
        t->a->n=NULL;
		t->e=t->a;
		t->sz=1;
        return (M*)t->a;
    }
    t->e->n=new M;
    t->e->n->p=t->e;
    t->e->n->n=NULL;
	t->e=t->e->n;
    t->sz++;
    return (M*)t->e;
}





// next	only
template < class D, class M>
M* _minsert_(D&t, M*m){

	if(t->sz<1){
        t->a=new M;
        t->a->n=NULL;
		t->e=t->a;
		t->sz=1;
        return (M*)t->a;
    }
    t->e->n=new M;
    t->e->n->n=NULL;
	t->e=t->e->n;
    t->sz++;
    return (M*)t->e;
}

//DELETE

//next prev
template <class D, class M>
int _mdelete(D &t, M*ind)
{
    if(t->sz==0)
        return 0;
	M *ni,*pi,*dl;
	if (ind->n) dl=ind->n->p;
	else if (ind->p) dl=ind->p->n;
	else {delete t->a; t->a=t->e=0; t->sz=0; return 1;}
    if (ind->n)  ni=ind->n; else 	ni=NULL;
	if (ind->p)  pi=ind->p; else 	pi=NULL;
	if (ni) ni->p=pi;
	else  t->e=ind->p;
	if (pi) pi->n=ni;
	else  t->a=ind->n;
	delete dl;
    t->sz--;
    return 1;
}

//next only, delete first element

template <class D, class M>
int _mdelete_(D &t, M*ind)
{
    if(t->sz==0)
        return 0;
	M *dl;
	if (t->sz==1)  {delete t->a; t->a=t->e=0; t->sz=0; return 0;}
	
	dl=t->a; t->a=t->a->n;
	delete dl;
	t->sz--;
    return 1;
}

//INSERT SORTED

// next // prev - standart
template < class D, class M>
M* _mssinsert(D&t, M*m, MString ms, int p){

	if(t->sz<1){
        t->a=new M;
        t->a->p=NULL;
        t->a->n=NULL;
		t->e=t->a;
		MString &tma=*(MString*)_mrap(t->a,p);
		tma=ms;
		t->sz=1;
        return (M*)t->a;
    }

//first sorted
MString &tma=*(MString*)_mrap(t->a,p);
if (tsor(ms, tma)>=0){
    t->a->p=new M;
    t->a->p->n=t->a;
    t->a->p->p=NULL;
	t->a=t->a->p;
	MString &tma=*(MString*)_mrap(t->a,p);
	tma=ms;
    t->sz++;
    return (M*)t->a;
}

//end sorted
MString &tme=*(MString*)_mrap(t->e,p);
if (tsor(ms, tme)==-1){
    t->e->n=new M;
    t->e->n->p=t->e;
    t->e->n->n=NULL;
	t->e=t->e->n;
	MString &tme=*(MString*)_mrap(t->a,p);
	tme=ms;
    t->sz++;
    return (M*)t->e;
}

M*ar=t->a;
while(ar){
MString tms=*(MString*)_mrap(ar,p);
if (tsor(ms, tms)==1){
	M*a=new M;
	ar->n->p=a;
	a->n=ar->n;
	ar->n=a;
	a->p=ar;
	MString tms=*(MString*)_mrap(a,p);
	tms=ms;
	t->sz++;
    return (M*)a;
}
ar=ar->n;
}

return 0;
}

// DELETE ALL

//for all types
template <class D, class M>
int _mdeleteall(D &t, M*ind)
{
    if(t->sz==0)
        return 0;
	
	M *dl=t->a, *n;


	while(dl){
	n=dl->n;
	delete dl;
	dl=n;
	}

	t->sz=0; t->a=t->e=0;
    return 1;
}


// CHANGE

//for all types
template <class D, class M>
int _change(D &t, M*ind, M*tind)
{
	M*pd=ind->p;
	if (t->a==ind) 
		t->a=tind;
	if (t->e==tind) 
		t->e=ind;
	ind->p=tind;
	ind->n=tind->n;
	tind->n=ind;
	tind->p=pd;

    return 1;
}		*/


////////////////////////////////
// NEW MATRIX 
class Line; // your class Index


// new class
class DLine : protected MMatrixXD
{
public:
DLine *_p,*_n;		// class data
MString s;			// add your data
};


class Line : protected MMatrixXD
{
public:
DLine *_a, *_e;	// class cell
unsigned int _sz;
	Line (){_a=_e=0; _sz=0;}	//new
	
	DLine* insert(const MString& s){ //insert
	//DLine*ind=_minsert(this, (DLine*)1); // 
	DLine*ind=(DLine*)_minsert((MMatrixR*)this, (MMatrixD*)new DLine); // 
	ind->s=s;
	return ind;
	}


	DLine* insert(){ //insert
	return (DLine*)_minsert((MMatrixR*)this, (MMatrixD*)new DLine); // 
	}

	MString* minsert(){ //insert
		return &((DLine*)_minsert((MMatrixR*)this, (MMatrixD*)new DLine))->s; // 
	}

	void del(DLine * ind){ //delete
		_mdelete((MMatrixR*)this, (MMatrixD*)ind);
		return ;
	
	 }

	void delall(){ //delete
		_mdeleteall((MMatrixR*)this, (MMatrixD*)this->_a);
		return ;
	
	 }

	DLine* Find(const MString& s){
	if(_sz==0)
    return 0;
	DLine*ar=_a;
	while(ar){
	if (ar->s==s) return ar;
	ar=ar->_n;
	}
	return 0;
	}

	MString dtake(){
	if (_a){
	MString ms=_a->s;
	del(_a);
	return ms;
	}
	return MString();
	}

	~Line(){ delall();}
};

/////////////////////////




////////////////////////////////
// NEW MATRIX 
class TLine; // your class Index


// new class
class DTLine : protected MMatrixXD
{
public:
DTLine *_p,*_n;		// class data
MString s;			// add your data
MString t;
};


class TLine : protected MMatrixXD
{
public:
DTLine *_a, *_e;	// class cell
unsigned int _sz;
	TLine (){_a=_e=0; _sz=0;}	//new
	
	DTLine* insert(const MString& s, const MString& t){ //insert
	DTLine*ind=(DTLine*)_minsert((MMatrixR*)this, (MMatrixD*)new DTLine); // 
	ind->s=s; ind->t=t;
	return ind;
	}

	DTLine* insert(){ //insert
	return (DTLine*)_minsert((MMatrixR*)this, (MMatrixD*)new DTLine); // 
	}

	TLine(TLine&lin){
	copy(&lin);
	}	  
	
	const TLine& operator=(TLine&lin){
	copy(&lin); return *this;
	}

	void copy(TLine*lin){
	DTLine*ln=lin->_a;
	while(ln){
		insert();
		_e->s=ln->s;
		_e->t=ln->t;
	//	if(ln->a)*e->a=*ln->a;
	ln=ln->_n;
	}}

	void del(DTLine * ind){ //delete
		_mdelete((MMatrixR*)this, (MMatrixD*)ind);
		return ;
	
	 }

	void delall(){ //delete
		_mdeleteall((MMatrixR*)this, (MMatrixD*)this->_a);
		return ;
	
	 }

	DTLine* Find(const MString& s){
	if(_sz==0)
    return 0;
	DTLine*ar=_a;
	while(ar){
	if (ar->s==s) return ar;
	ar=ar->_n;
	}
	return 0;
	}

	MString dtake(){
	if (_a){
	MString ms=_a->s;
	del(_a);
	return ms;
	}
	return MString();
	}

	~TLine(){ delall();}
};

/////////////////////////


////////////////////////////////
// NEW MATRIX 
class ILine; // your class Index


// new class
class DILine : protected MMatrixXD
{
public:
DILine *_p,*_n;		// class data
int i;			// add your data
};


class ILine : protected MMatrixXD
{
public:
DILine *_a, *_e;	// class cell
unsigned int _sz;
	ILine (){_a=_e=0; _sz=0;}	//new
	
	DILine* insert(int i){ //insert
	DILine*ind=(DILine*)_minsert((MMatrixR*)this, (MMatrixD*)new DILine); // 
	ind->i=i;
	return ind;
	}

	DILine* insert(){ //insert
	return (DILine*)_minsert((MMatrixR*)this, (MMatrixD*)new DILine); // 
	}

	void del(DILine * ind){ //delete
		_mdelete((MMatrixR*)this, (MMatrixD*)ind);
		return ;
	
	 }

	void delall(){ //delete
		_mdeleteall((MMatrixR*)this, (MMatrixD*)this->_a);
		return ;
	
	 }

	DILine* Find(int i){
	if(_sz==0)
    return 0;
	DILine*ar=_a;
	while(ar){
	if (ar->i==i) return ar;
	ar=ar->_n;
	}
	return 0;
	}

	int dtake(){
	if (_a){
	int ms=_a->i;
	del(_a);
	return ms;
	}
	return int();
	}

	~ILine(){ delall();}
};

/////////////////////////

////////////////////////////////
// NEW MATRIX 
class ISLine; // your class Index


// new class
class DISLine : protected MMatrixXD
{
public:
DISLine *_p,*_n;		// class data
MString s;			// add your data
int i;
};


class ISLine : protected MMatrixXD
{
public:
DISLine *_a, *_e;	// class cell
unsigned int _sz;
	ISLine (){_a=_e=0; _sz=0;}	//new
	
	DISLine* insert(const MString& s, int i){ //insert
	DISLine*ind=(DISLine*)_minsert((MMatrixR*)this, (MMatrixD*)new DISLine); // 
	ind->s=s; ind->i=i;
	return ind;
	}

	DISLine* insert(){ //insert
	return (DISLine*)_minsert((MMatrixR*)this, (MMatrixD*)new DISLine); // 
	}

	void del(DISLine * ind){ //delete
		_mdelete((MMatrixR*)this, (MMatrixD*)ind);
		return ;
	
	 }

	void delall(){ //delete
		_mdeleteall((MMatrixR*)this, (MMatrixD*)this->_a);
		return ;
	
	 }

	DISLine* Find(const MString& s){
	if(_sz==0)
    return 0;
	DISLine*ar=_a;
	while(ar){
	if (ar->s==s) return ar;
	ar=ar->_n;
	}
	return 0;
	}

	MString dtake(){
	if (_a){
	MString ms=_a->s;
	del(_a);
	return ms;
	}
	return MString();
	}

	~ISLine(){ delall();}
};

/////////////////////////

////////////////////////////////
// NEW MATRIX 
class XLine: protected MMatrixXD	// your class
{
public:
XLine *_a, *_e, *_p, *_n;	// class data
unsigned int _sz;			// class data
MString string;			// add your data

	XLine (){_a=0; _e=0; _p=0; _n=0; _sz=0;}	//new
	
	XLine* insert(const MString& text){ //insert
	//DLine*ind=_minsert(this, (DLine*)1); // 
	XLine*ind=(XLine*)_minsertx((MMatrixX*)this, (MMatrixX*)new XLine); // 
	ind->string=text;
	return ind;
	}

	XLine* insert(){ //insert
	return (XLine*)_minsertx((MMatrixX*)this, (MMatrixX*)new XLine); // 
	}

	void del(XLine * ind){ //delete
		_mdeletex((MMatrixX*)&_a, (MMatrixX*)ind);
		return ;
	 }

	void clear(){ //delete
		_mdeleteallx((MMatrixX*)&_a, (MMatrixX*)this->_a);
		return ;
	}
/*
	XLine* Find(MString string){
	if(_sz==0) return 0;
	XLine*ar=_a;
	while(ar){
	if (ar->string==string) return ar;
	ar=ar->_n;
	}
	return 0;
	}

	MString dtake(){
	if (_a){
	MString ms=_a->string;
	del(_a);
	return ms;
	}
	return MString();
	}
	*/
	~XLine(){ clear();}
	
};

/////////////////////////



////////////////////////////////
// NEW MATRIX 
class DXLine: protected MMatrixXD	// your class
{
public:
DXLine *_a, *_e, *_p, *_n;	// class data
unsigned int _sz;			// class data
MString s;					// add your data
MString t;

	DXLine (){_a=0; _e=0; _p=0; _n=0; _sz=0;}	//new
	
	DXLine* insert(const MString& s, const MString& t){ //insert
	//DLine*ind=_minsert(this, (DLine*)1); // 
	DXLine*ind=(DXLine*)_minsertx((MMatrixX*)this, (MMatrixX*)new DXLine); // 
	ind->s=s; ind->t=t;
	return ind;
	}

	DXLine* insert(){ //insert
	return (DXLine*)_minsertx((MMatrixX*)this, (MMatrixX*)new DXLine); // 
	}

	void del(void * ind){ //delete
		_mdeletex((MMatrixX*)this, (MMatrixX*)ind, this);
		return ;
	}

	void destroy(void *ind){delete (DXLine*)ind;}

	void clear(){ //delete
		_mdeleteallx((MMatrixX*)this, this);
		return ;
	}

	DXLine* Find(const MString& string){
	if(_sz==0) return 0;
	DXLine*ar=_a;
	while(ar){
	if (ar->s==string) return ar;
	ar=ar->_n;
	}
	return 0;
	}

	

	~DXLine(){ clear();}
	
};

/////////////////////////





/////////////////////////
//MMATRIX CURSOR
class CXLine{
ILine il;
public:
MMatrixX *root, *xline;

CXLine(MMatrixX *rot){root=0; xline=rot;}
CXLine(MMatrixX rot){root=0; xline=&rot;}

operator void*(){return xline;}

//MString& s(){return xline->string;}

public:
	int Prev(){
		if (xline->_p) {xline = xline->_p; return 1;}
		return 0;
	}

	int Next(){
		if (xline->_n) {xline = xline->_n; return 1;}
		return 0;
	}

	int Up(){
		if(xline->_a) { il.insert(vti(root)); root=xline; xline=xline->_a; return 1;}
		return 0;
	}

	int EUp(){
		if(xline->_e) { il.insert(vti(root)); root=xline; xline=xline->_e; return 1;}
		return 0;
	}

	int Down(){
		xline=root;
		if(il._e) { root=(MMatrixX *)(int*)&il._e->i;  il.del(il._e); return 1;}
		else root=0;
		return 0;
	}

	~CXLine(){il.delall();}

};
/*
template <class D>
int explode(D &ret, const MString& line, const MString fr, int c, bool a, bool r){
												//	    =0		=0		=0
if (!r){	
if (fr.size()==1){
int l=0, pos=0, lpos=0, err;

while(1){
err=rts(line, fr, pos);
if (err) { if(c) if(l==c) {	if (a) {ret[l].Reserv(line.size()-lpos); memcpy(ret[l].rchar(), line.pos(lpos), line.size()-lpos); return l+1;}
								else return l;
							}
		ret[l].Reserv(pos-lpos); memcpy(ret[l].rchar(), line.pos(lpos), pos-lpos); l++; }
else { if(!c || l!=c || a) if (lpos!=pos){ ret[l].Reserv(pos-lpos); memcpy(ret[l].rchar(), line.pos(lpos), pos-lpos); l++;}
	 return l;}
pos++; lpos=pos;
}}

int l=0, pos=0, lpos=0, err;
while(1){
err=rtms(line, fr, pos);
if (err) {  if(c) if(l==c) {	if (a) {ret[l].Reserv(line.size()-lpos); memcpy(ret[l].rchar(), line.pos(lpos), line.size()-lpos); return l+1;}
								else {ret[l].Reserv(pos-lpos); memcpy(ret[l].rchar(), line.pos(lpos), pos-lpos); return l+1;}
							}
	ret[l].Reserv(pos-lpos); memcpy(ret[l].rchar(), line.pos(lpos), pos-lpos); l++; }
else {if(!c || l!=c || a) if (lpos!=pos){ ret[l].Reserv(pos-lpos); memcpy(ret[l].rchar(), line.pos(lpos), pos-lpos); l++;}
	return l;}
pos+=fr.size(); lpos=pos;
}}
else{
if (fr.size()==1){
int l=0, pos=line.size(), lpos=line.size()-1, err;

while(1){
err=rrts(line, fr, pos);
if (err) { if(c) if(l==c) {	if (a) {ret[l].Reserv(lpos+1); memcpy(ret[l].rchar(), line.pos(0), lpos+1); return l+1;}
								else return l;
							}	
	ret[l].Reserv(lpos-pos); memcpy(ret[l], line.pos(pos+1), lpos-pos); l++; }
else { if(!c || l!=c || a) if (lpos!=pos){ ret[l].Reserv(lpos-pos); memcpy(ret[l].rchar(), line, lpos-pos); l++;}
		return l;}
pos--; lpos=pos;
}}

int l=0, pos=line.size()-1, lpos=line.size()-1, err;
while(1){
err=rtms(line, fr, pos, 1);
if (err) { ret[l].Reserv(pos-lpos); memcpy(ret[l].rchar(), line.pos(lpos+1), pos-lpos); l++; }
else if(!c || l!=c || a) if (lpos!=pos){ ret[l].Reserv(pos-lpos); memcpy(ret[l].rchar(), line.pos(lpos), pos-lpos); l++;}
	else {if(a) {ret[l].Reserv(line.size()-lpos); memcpy(ret[l].rchar(), line.pos(lpos), line.size()-lpos); l++;}  return l;}
pos-=fr.size(); lpos=pos;
}}
return 0;
}

template <class D>
int explodem(D &ret, const MString& line, const MString fr, int c=0, bool a=0, bool r=0){
int l=0, pos=0, lpos=0, err;						//	    =0		=0		=0
if (!r){
if (fr.size()==1){
char cfr=fr[0];

while(1){
err=rts(line, cfr, pos);
if (err) { if(c) if(l==c) {	if (a) {*ret.minsert()=line.str(lpos, line.size()-lpos); return l+1;}
								else return l;
							}
		*ret.minsert()=line.str(lpos, pos-lpos);
}
else { if(!c || l!=c || a) if (lpos!=pos){ *ret.minsert()=line.str(lpos, pos-lpos); l++;}
	 return l;}
pos++; lpos=pos;
}}

while(1){
err=rtms(line, fr, pos);
if (err) {  if(c) if(l==c) {	if (a) {*ret.minsert()=line.str(lpos, line.size()-lpos); return l+1;}
								else {*ret.minsert()=line.str(lpos, pos-lpos); return l+1;}
							}
	*ret.minsert()=line.str(lpos, pos-lpos); l++; }
else { if(!c || l!=c || a) if (lpos!=pos){ *ret.minsert()=line.str(lpos, pos-lpos); l++;}
	return l;}
pos+=fr.size(); lpos=pos;
}}
else{/*
if (fr.size()==1){
int l=0, pos=line.size(), lpos=line.size()-1, err; char cfr=fr[0];

while(1){
err=rrts(line, cfr, pos);
if (err) { if(c) if(l==c) {	if (a) {ret[l].Reserv(lpos+1); memcpy(ret[l].rchar(), line.pos(0), lpos+1); return l+1;}
								else return l;
							}	
	ret[l].Reserv(lpos-pos); memcpy(ret[l], line.pos(pos+1), lpos-pos); l++; }
else { if (lpos!=pos){ ret[l].Reserv(lpos-pos); memcpy(ret[l].rchar(), line, lpos-pos); l++;}
		return l;}
pos--; lpos=pos;
}}

int l=0, pos=line.size()-1, lpos=line.size()-1, err;
while(1){
err=rtms(line, fr, pos, 1);
if (err) { ret[l].Reserv(pos-lpos); memcpy(ret[l].rchar(), line.pos(lpos+1), pos-lpos); l++; }
else if (lpos!=pos){ ret[l].Reserv(pos-lpos); memcpy(ret[l].rchar(), line.pos(lpos), pos-lpos); l++;}
	else {if(a) {ret[l].Reserv(line.size()-lpos); memcpy(ret[l].rchar(), line.pos(lpos), line.size()-lpos); l++;}  return l;}
pos-=fr.size(); lpos=pos;
}* /}
return 0;
}*/

 


// ADDED SP MATRIX

   ////////////////////////////////
// NEW MATRIX 
class VMLine; // your class Index


// new class
class DVMLine : protected MMatrixXD
{
public:
DVMLine *p,*n;		// class data
MString *s;			// add your data
int i;

};


class VMLine : protected MMatrixXD
{
public:
DVMLine *a, *e;	// class cell
unsigned int sz;
	VMLine (){a=e=0; sz=0;}	//new
	
	DVMLine* insert(MString *s){ //insert
	DVMLine*ind=(DVMLine*)_minsert((MMatrixR*)this, (MMatrixD*)new DVMLine); // 
	ind->s=s;
	return ind;
	}

	DVMLine* insert(){ //insert
	return (DVMLine*)_minsert((MMatrixR*)this, (MMatrixD*)new DVMLine); // 
	}

	void del(DVMLine * ind){ //delete
		_mdelete((MMatrixR*)this, (MMatrixD*)ind);
		return ;
	
	 }

	void delall(){ //delete
		_mdeleteall((MMatrixR*)this, (MMatrixD*)this->a);
		return ;
	
	 }

	DVMLine * Find(const MString& ms, int i){
		DVMLine*dl=a;
		while(dl){
			if(dl->s[i]==ms) return dl;
		dl=dl->n;
		}
	return 0;
	}


	~VMLine(){ delall();}
};

/////////////////////////
typedef void* LPVOID;
typedef XLine* (*LPCCTHREAD_METHOD)(XLine mmatrix, LPVOID pParam);
