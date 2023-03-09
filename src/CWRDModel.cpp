#include "CWRDModel.h"




NWRD::CModel::CModel() {
}



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CModel& a_model ) {

    a_out << a_model.f_GetPoint()
        << ": \""
        << a_model.f_GetTexture()
        << "\"";


    return a_out;
}
