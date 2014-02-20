// Schriftzug als Extra
#declare box_text = text {
      ttf "timrom.ttf" "_mperlet Mediabox 2013/2014" 20, 0
      pigment { Black }
    }

// USB-Ports und Karten-Slot
// schneidet die Ports aus der Mediabox
#declare port_hobel = union {
    
    // USB Port 1
    box{ <0,0,0>, <1.5, 0.5 ,3>
         pigment{ color Blue }
         rotate<0,0,0>
         translate<4,2,-1>
    }
    
    // USB Port 2
    box{ <0,0,0>, <1.5, 0.5 ,3>
         pigment{ color Blue }
         rotate<0,0,0>
         translate<7,2,-1>
    }
    
    // Kartenlesegerät
    box{ <0,0,0>, <10, 0.2 ,3>
         pigment{ color Blue }
         rotate<0,0,0>
         translate<12,2,-1>
    }
}

// Mediabox mit runden Ecken, vier Stützen, einer Antenne und
// einem Drehschalter
#declare mediabox = union {
    
    // Mediabox
    intersection {
        // Mediabox "Box"
        box{ <0,0,0>, <40, 6 ,20>
            texture { Silver_Metal }
            rotate<0,0,0>
            translate<0,0,0>
        }
        // Zylinder für die runden Ecken
        cylinder{ <20,-20,-1>,<20, -20 ,21>, 30
            texture { Silver_Metal }
        }
    }


    object{box_text translate<5,4,0>}
    
    // Stütze Mediabox vorne links
    cylinder{ <5,-1,5>,<5, 0 ,5>, 2
        pigment{ color Orange}
    }
      
    // Stütze Mediabox hinten links
    cylinder{ <5,-1,15>,<5, 0 ,15>, 2
        pigment{ color Orange}
    }
    
    // Stütze Mediabox vorne rechts
    cylinder{ <35,-1,5>,<35, 0 ,5>, 2
        pigment{ color Orange}
    }
    
    // Stütze Mediabox hinten rechts
    cylinder{ <35,-1,15>,<35, 0 ,15>, 2
        pigment{ color Orange}
    }
    
    // Laut/Leise Drehschalter
    cylinder{ <30,3,0>,<30, 3,-1>, 1.5
        texture { Brass_Metal }
    }
    
    // Antenne
    cylinder{ <8, 6,17>,<8, 22,17>, 0.2
        texture { Chrome_Metal }
    } 
}

// Mediabox Object bekommt hier die USB/Karten Slots
// endgültige Mediabox
#declare mediabox = difference {
    object{ mediabox }
    object{ port_hobel }
}
