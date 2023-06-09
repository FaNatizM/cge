﻿#ifndef CPOINT_H
#define CPOINT_H


#include <memory>
#include <iostream>
#include <vector>




using TCoord = int;




class CPoint {
    public:
        explicit CPoint(
            const TCoord a_x = -1
            , const TCoord a_y = -1 );

        ~CPoint();

        CPoint( const CPoint& a_point );
        CPoint& operator=(
            const CPoint& a_point );

        CPoint( CPoint&& a_point );
        CPoint& operator=(
            CPoint&& a_point );

        bool operator==(
            const CPoint& a_other )
            const;

        bool operator<(
            const CPoint& a_other )
            const;

        bool f_IsNull() const;

        TCoord f_GetX() const;
        TCoord f_GetY() const;


    private:
        struct SImpl;
        using TImpl
            = std::unique_ptr<
               SImpl >;
        TImpl m_impl;
};



using TPoints = std::vector< CPoint >;




bool f_IsAdjacent(
    const CPoint& a_left
    , const CPoint& a_right );



std::ostream& operator<<(
    std::ostream& a_out
    , const CPoint& a_point );



std::ostream& operator<<(
    std::ostream& a_out
    , const TPoints& a_points );




#endif
