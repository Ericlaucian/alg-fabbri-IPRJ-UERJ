/*R. Fabbri, 2024 */
#include "sorted_merge_3way.h"
#include <climits>

bool
sorted_merge_3way(
    const int *list_a, int na,
    const int *list_b, int nb,
    const int *list_c, int nc,
    int *list_abc)
{

	int j{0}, k{0}, l{0}, last{INT_MIN};
    	for (int i = 0; i < na + nb + nc; ++i) {
        	int a = list_a[j], b = list_b[k], c = list_c[l];

        	if (j >= na) {a = INT_MAX;}
        	if (k >= nb) {b = INT_MAX;}
        	if (l >= nc) {c = INT_MAX;}

        	if (a <= b && a <= c) {
        		list_abc[i] = a;
			if (a < last) return false;
        	    	++j;
        	}
        	if (b <= a && b <= c) {
			if (b < last) return false;
        		list_abc[i] = b;
        	    	++k;
        	}
		if(c <= a && c <= b){
			if (c < last) return false;
	       		list_abc[i] = c;
        		++l;
		}

		last = list_abc[i];
    	}

 	 return true; // stub

}
