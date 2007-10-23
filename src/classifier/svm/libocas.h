/*--------------------------------------------------------------------
 *  Implementation of SVM-Ocas solver. 
 *
 *  Linear binary SVM solver without bias term.
 *
 * Modifications:
 * 10-oct-2007, VF, created.
 * ----------------------------------------------------------------------*/

#include <stdint.h>

typedef struct {
  uint32_t nIter;      
  double trn_err;      
  double Q_P;          
  double Q_D;
  double output_time;
  double sort_time;
  double solver_time;
  int8_t exitflag;       
} ocas_return_value_T;


ocas_return_value_T svm_ocas_solver(
            double C,
            uint32_t nData, 
            double TolRel,
            double TolAbs,
            double QPBound,
            uint32_t BufSize,
            uint8_t Method,
            void (*compute_W)(double*, double*, double*, uint32_t),
            double (*update_W)(double),
            void (*add_new_cut)(double*, uint32_t*, uint32_t, uint32_t),
            void (*compute_output)( double* ),
            void (*sort)(double*, uint32_t*, uint32_t));


void qsort_index(double* value, uint32_t* index, uint32_t size);
