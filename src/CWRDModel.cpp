#include "CWRDModel.h"

#include <cassert>




NWRD::CModel::CModel() {
}



NWRD::CObject
NWRD::CModel::f_GetObject(
    const int ) const {
    return CObject();
}



CPoint
NWRD::CModel::f_GetPoint(
    const int ) const {
    return CPoint();
}



NGE::CTexture
NWRD::CModel::f_GetTexture(
    const int ) const {
    return
        NGE::CTexture();
}



size_t
NWRD::CModel::f_GetObjectsCount()
    const {
    return 0;
}



bool NWRD::CModel::f_Loop(
    const TOperation& ) {
    return true;
}



TPoints NWRD::CModel::f_CheckMove(
    const CPoint& a_point )
    const {
    return TPoints();
}



bool NWRD::CModel::f_Move(
    const TPoints& a_points ) {
    return false;
}



std::ostream& NWRD::CModel::f_Visual(
    std::ostream& a_out )
    const {
    a_out << "empty model";
    return a_out;
}



void NWRD::CModel::f_Test() {
    auto model = CModel();
    std::cout << "model: "
        << model << std::endl;

    assert( model.f_GetObject()
        .f_IsNull() == true );

    assert( model.f_GetPoint()
        .f_IsNull() == true );

    assert( model.f_GetTexture()
        .f_IsUndefined() == true );

    assert( model.f_GetObjectsCount()
        == 0 );

    assert(
        model.f_Move( { CPoint( 1, 1 ) } )
        == false );
}



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::CModel& a_model ) {
    return a_model.f_Visual( a_out );
}



std::ostream& operator<<(
    std::ostream& a_out
    , const NWRD::TModel& a_model ) {
    return a_model->f_Visual( a_out );
}
