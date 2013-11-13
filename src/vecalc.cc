/* Kennedy Slawinski
 * kts192
 * 11053598
 * CMPT 214 Assignment 2
 */

#include <cstdlib>
#include <cstdio>
#include "assert.h"



#define TESTING = 1; //turn on testing, later just use gcc

typedef float Elem;

typedef struct Vector{
		unsigned int Size;
		Elem *ptr;
};

bool print_vec(Vector *vec)
{
	if (vec == NULL)
		return false;
	else
	{
		for (int i = 0; i<vec->Size; i++)
		{
			printf("%1f ",vec->ptr[i]);
		}
		return true;
	}
}

/* Precon: 	none
 * Postcon: return's a pointer to a Vector with size 0
 * 			and a null Elem ptr array
 */
Vector *alloc_vec()
{
	Vector *newVec = new Vector;
	newVec->Size = 0;
	newVec->ptr = NULL;
	return newVec;

}
/*
 * Precon: 	vec is a pointer to a Vector
 * Postcon: vec has had it's ptr array deleted
 *			the Size has been set to zero
 *			vec is deleted
 */
void dealloc_vec(Vector *vec)
{
	delete[] vec->ptr;
	vec->ptr = NULL;
	vec->Size = 0;
	delete vec;
}
/* Precon: 	vec is a pointer to a vector
 * 			elem is the elem to be appended to the new vector
 * Postcon:	vec is deallocated, newVec has all of the values
 * 			of vec, plus the newly appended elem.
 * Return:	newVec is returned
 */
Vector *extend_vec(Vector *vec, Elem elem)
{
	Vector *newVec = new Vector;
	newVec->Size = vec->Size+1;
	newVec->ptr = new Elem[newVec->Size];
	if (vec->Size != NULL)
	{
		for (int i = 0; i<vec->Size; i++)
		{
			newVec->ptr[i] = vec->ptr[i];
		}
	}
	newVec->ptr[newVec->Size-1] = elem;
	dealloc_vec(vec);
	return newVec;
}

/* Precon: 	vec is a pointer to a vector
 * 			elem is the Elem to be added to each Elem currently
 * 			in the array
 * Postcon:	all of the Elem's have had elem added to them
 * Return:	vec is returned.
 */
Vector *scalar_plus(Vector *vec, Elem elem)
{
	for (int i = 0; i<vec->Size; i++)
	{
		vec->ptr[i] = vec->ptr[i]+elem;
	}
	return vec;
}

//TODO STUBS Do the Pre/Post cons for these bad boys

Vector *scalar_minus(Vector *, Elem)
{
	return NULL;
}

Vector *scalar_mult(Vector *, Elem)
{
	return NULL;
}

Vector *scalar_div(Vector *, Elem)
{
	return NULL;
}

// Instruct user on how to use this program; i.e. the commands it
// supports and the syntax of those commands.
// In:
//    none
// Out:
//    output produced on standard output
void usage( void )
{
    puts( " Usage:" );
    puts( "  p   - print vector" );
    puts( "  q,e - quit, end" );
    puts( "  h   - print usage help" );
    puts( "  + <operand> - add <operand> to each element of vector" );
    puts( "  - <operand> - subtract <operand> from each element of vector" );
    puts( "  * <operand> - multiple each element of vector by <operand>" );
    puts( "  / <operand> - divide each element of vector by <operand>" );
    puts( "  a <value> - extend vector by additional value" );
}

/* Function that runs the program
 * Has TESTING field that can be enabled to test the functions.
 * Precon:	The functions called in the main work
 * Postcon:	Something has hopefully been accomplished
 * Return:	0
 */
int main(int, char**)
{

	#ifdef TESTING
		Vector *newVec = alloc_vec();

		//Verify newVec has a NULL pointer and size 0
		assert(newVec->ptr == NULL);
		assert(newVec->Size == 0);


		//Ensure's extend_vec is working.
		newVec = extend_vec(newVec, 100.0);
		assert(newVec->ptr[0] == 100.0);
		newVec = extend_vec(newVec, -50.0);
		assert(newVec->ptr[1] == -50.0);


		//Ensure scalar_plus is working
		newVec = scalar_plus(newVec, 13.0);
		assert(newVec->ptr[0] == 113.0);
		assert(newVec->ptr[1] == -37.0);

		//Ensure print_vec is functioning correctly.
		print_vec(newVec);

		//Verify newVec has been deallocated
		dealloc_vec(newVec);
		assert(newVec->ptr == NULL);


	#endif

	return 0;
}
