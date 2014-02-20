
#declare n_strebe = union {
    // bein links vorn
    cylinder {<0,0,0>,<0,25,0>,1.5}

    // bein rechts vorn
    cylinder {<10,0,0>,<10,25,0>,1.5}

    //querstrebe links vorn unten nach rechts vorn oben
    cylinder {<0,1,0>,<10,24,0>,1 }
}
#declare streben_stueck = union {
    object { n_strebe texture {Silver_Metal} }
    object { n_strebe rotate<180,0,0> translate <0,25,10> texture {Silver_Metal} }
    object { n_strebe rotate<180,90,0> translate <0,25,10> texture {Silver_Metal} }
    object { n_strebe rotate<0,90,0> translate<10,0,10> texture {Silver_Metal} }
}

#declare streben_stueck_halber_meter = union {
object{streben_stueck}
object{streben_stueck rotate<0,90,0> translate<0,25,10>}
}

#declare zwei_m_strebe = union {
    object {streben_stueck_halber_meter}
    object {streben_stueck_halber_meter translate<0,50,0>}
    object {streben_stueck_halber_meter translate<0,100,0>}
    object {streben_stueck_halber_meter translate<0,150,0>}
    object {streben_stueck_halber_meter translate<0,200,0>}
}
#declare geruest = union {
    //streben vertikal
    object {zwei_m_strebe translate<-165,10,-165>}
    object {zwei_m_strebe translate<165,10,-165>}
    object {zwei_m_strebe translate<165,10,165>}
    object {zwei_m_strebe translate<-165,10,165>}

    //streben oben links
    object {zwei_m_strebe rotate<90,0,0> translate<-165,260,-50>}
    object {zwei_m_strebe rotate<90,0,0> translate<-165,260,-250>}

    //streben oben rechts
    object {zwei_m_strebe rotate<90,0,0> translate<165,260,-50>}
    object {zwei_m_strebe rotate<90,0,0> translate<165,260,-250>}

    //streben hinten
    object {zwei_m_strebe rotate<90,90,0> translate<0,270,165>}
    object {zwei_m_strebe rotate<90,90,0> translate<-230,270,165>}
}


// Lampenschirm
#declare lampe = difference {
    cone { <0,0,0>,10, <0,20,0>, 30}
    cone { <0,5,0>,10, <0,25,0>, 30}
}

#declare scheinwerfer = union {
// Lichtquelle hinten Links
light_source{ <-150,250,50> color rgb <1,1,1>   
              spotlight
              point_at<0,0,0>
              radius 100  // hotspot
              tightness 5
              
            }
// Lampenschirm hinten links
object { lampe texture { Silver_Metal } rotate<180,0,45> translate<-155,255,50>}

// Lichtquelle hinten rechts
light_source{ <150,250,50> color rgb <1,1,1>   
              spotlight
              point_at<0,0,0>
              radius 100  // hotspot
              tightness 5
              
            }
// Lampenschirm hinten rechts
object { lampe texture { Silver_Metal } rotate<180,0,-45> translate<155,255,50>}


// Lichtquelle vorne links
light_source{ <-150,250,-50> color rgb <1,1,1>   
              spotlight
              point_at<0,0,0>
              radius 100  // hotspot
              tightness 5
              
            }
            
// Lampenschirm vorne links
object { lampe texture { Silver_Metal } rotate<180,0,45> translate<-155,255,-50>}

// Lichtquelle vorne rechts
light_source{ <150,250,-50> color rgb <1,1,1>   
              spotlight
              point_at<0,0,0>
              radius 100  // hotspot
              tightness 5
              
            }
// Lampenschirm vorne rechts
object { lampe texture { Silver_Metal } rotate<180,0,-45> translate<155,255,-50>}
}
