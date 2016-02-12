#include "ia_alphabeta.h"
#include "coup.h"
#include "plateau.h"

#include "omp.h"
//#include <mpi/mpi.h>

#include <vector>
#include <climits>

IA_AlphaBeta::IA_AlphaBeta(plateau *p) {
    this->p = p;
    this->bestCoup = NULL;
    this->depth = 2;
}

void IA_AlphaBeta::setDepth(unsigned int depth) {
    this->depth = depth;
}

void IA_AlphaBeta::jouerParalleleAlphaBeta() {
    int nb_threads = 4;
    int value;
    int value_min = INT_MAX;
    std::vector< coup* > listCoup = p->getListCoup( false );

    int taille = listCoup.size();
    taille = taille / nb_threads;

    #pragma omp parallel num_threads(nb_threads) shared(value_min)
    {
        #pragma omp critical
        {
            int min = omp_get_thread_num() * taille;
            int max = listCoup.size();
            if( (min + 2 * taille) < max ){
                max = min + taille;
            }
            for (int i = min; i < max; ++i) {
                coup* c = listCoup.at(i);
                p->jouerCoup(c);

                value = ab_max_min(p, INT_MIN, INT_MAX, depth-1);

                p->getBack(c);

                if (value <= value_min) {
                    value_min = value;
                    this->bestCoup = c;
                }
            }
        }
    }

    p->jouerCoup( bestCoup );
    p->majPlateau();
}

void IA_AlphaBeta::jouerMultiprocessAlphaBeta() {
//    // Initialize the MPI library:
//    MPI::Init(argc, argv);

//    // Get the number of processors this job is using:
//    int rank = MPI::COMM_WORLD.Get_rank();

//    // Get the rank of the processor this thread is running on.  (Each
//    // processor has a unique rank.)
//    int size = MPI::COMM_WORLD.Get_size();

//    // Get the name of this processor (usually the hostname).  We call
//    // memset to ensure the string is null-terminated.  Not all MPI
//    // implementations null-terminate the processor name since the MPI
//    // standard specifies that the name is *not* supposed to be returned
//    // null-terminated.
//    char name[MPI_MAX_PROCESSOR_NAME];
//    int len;
//    memset(name,0,MPI_MAX_PROCESSOR_NAME);
//    MPI::Get_processor_name(name,len);
//    memset(name+len,0,MPI_MAX_PROCESSOR_NAME-len);

//    cout << "hello_parallel.cc: Number of tasks="<<size<<" My rank=" << rank << " My name="<<name<<"."<<endl;

//    // Tell the MPI library to release all resources it is using:
//    MPI::Finalize();

    cout << "Empty !" << endl;
}

void IA_AlphaBeta::HW() {
    cout<<"H   H EEEEE L     L      OOO   !!  "<<endl
        <<"H   H E     L     L     O   O  !!  "<<endl
        <<"HHHHH EEEE  L     L     O   O  !!  "<<endl
        <<"H   H E     L     L     O   O      "<<endl
        <<"H   H EEEEE LLLLL LLLLL  OOO   !!  "<<endl;
}


/* Calcul du meilleur coup des noirs */
void IA_AlphaBeta::jouerAlphaBeta() {
    int value;
    int value_min = INT_MAX;
    std::vector< coup* > listCoup = p->getListCoup( false );
    foreach (coup *c, listCoup) {
        p->jouerCoup(c);

        value = ab_max_min(p, INT_MIN, INT_MAX, depth-1);

        p->getBack(c);

        if (value < value_min) {
            value_min = value;
            this->bestCoup = c;
        }
    }

    p->jouerCoup( bestCoup );
    p->majPlateau();
}

/* Calcul le meilleur coup pour les blancs */
void IA_AlphaBeta::jouerBetaAlpha() {
    int value;
    int value_max = INT_MIN;
    std::vector< coup* > listCoup = p->getListCoup( true );
    foreach (coup *c, listCoup) {
        p->jouerCoup(c);

        value = ab_min_max(p, INT_MIN, INT_MAX, depth-1);

        p->getBack(c);

        if (value >= value_max) {
            value_max = value;
            this->bestCoup = c;
        }
    }

    p->jouerCoup( bestCoup );
    p->majPlateau();
}

int IA_AlphaBeta::ab_min_max(plateau *child, int alpha, int beta, unsigned int level) {

    // joueur1 == false
    if (child->checkMateKing(false)) {
        return INT_MAX;
    }
    if (level == 0) {
        return child->evaluation();
    }

    std::vector< coup* > listCoup = p->getListCoup( true );
    int value;

    foreach (coup *c, listCoup) {
        child->jouerCoup(c);

        value = ab_max_min(p, alpha, beta, level-1);

        child->getBack(c);

        if (value < beta) {
            beta = value;
            if (alpha > beta) {
                return beta;
            }
        }
    }

    return beta;
}

int IA_AlphaBeta::ab_max_min(plateau *child, int alpha, int beta, unsigned int level) {

    // joueur1 == true
    if (child->checkMateKing(true)) {
        return INT_MIN;
    }
    if (level == 0) {
        return child->evaluation();
    }

    std::vector< coup* > listCoup = p->getListCoup(false);
    int value;

    foreach (coup *c, listCoup) {
        child->jouerCoup(c);

        value = ab_min_max(p, alpha, beta, level-1);

        child->getBack(c);

        if (value > alpha) {
            alpha = value;
            if (alpha > beta) {
                return alpha;
            }
        }
    }

    return alpha;
}
