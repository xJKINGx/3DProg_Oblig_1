#include "house.h"

house::house() {

}

house::house(float scale, QVector3D start) {
    m_Position = start;
    // MAIN BODY
    // FRONT LEFT
    Vertex v1{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v2{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v3{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v4{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v5{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v6{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    // FRONT UPPER
    Vertex v7{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v8{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v9{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v10{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v11{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v12{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    // FRONT RIGHT
    Vertex v13{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v14{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v15{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v16{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v17{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v18{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    // WEST
    Vertex v19{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v20{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v21{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v22{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v23{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v24{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    // BACK
    Vertex v25{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v26{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v27{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v28{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v29{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v30{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};

    // EAST
    Vertex v31{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v32{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v33{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v34{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v35{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v36{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};


    // UPPER PART
    // WEST
    Vertex v37{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v38{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale/2 + scale, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v39{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*5, m_Position[2] + StartPos[2] + scale/2 + scale, HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v40{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v41{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale + scale/2, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v42{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*5, m_Position[2] + StartPos[2] + scale + scale/2, HouseColour[0], HouseColour[1], HouseColour[2]};

    // EAST
    Vertex v43{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v44{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale/2 + scale, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v45{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*5, m_Position[2] + StartPos[2] + scale/2 + scale, HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v46{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v47{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale + scale/2, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v48{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*5, m_Position[2] + StartPos[2] + scale + scale/2, HouseColour[0], HouseColour[1], HouseColour[2]};


    // ROOF
    // FRONT
    Vertex v49{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], RoofColour[0], RoofColour[1], RoofColour[2]};
    Vertex v50{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], RoofColour[0], RoofColour[1], RoofColour[2]};
    Vertex v51{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*5, m_Position[2] + StartPos[2] + scale + scale/2, RoofColour[0], RoofColour[1], RoofColour[2]};

    Vertex v52{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], RoofColour[0], RoofColour[1], RoofColour[2]};
    Vertex v53{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*5, m_Position[2] + StartPos[2] + scale + scale/2, RoofColour[0], RoofColour[1], RoofColour[2]};
    Vertex v54{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*5, m_Position[2] + StartPos[2] + scale + scale/2, RoofColour[0], RoofColour[1], RoofColour[2]};

    // BACK
    Vertex v55{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, RoofColour[0], RoofColour[1], RoofColour[2]};
    Vertex v56{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, RoofColour[0], RoofColour[1], RoofColour[2]};
    Vertex v57{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*5, m_Position[2] + StartPos[2] + scale + scale/2, RoofColour[0], RoofColour[1], RoofColour[2]};

    Vertex v58{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, RoofColour[0], RoofColour[1], RoofColour[2]};
    Vertex v59{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*5, m_Position[2] + StartPos[2] + scale + scale/2, RoofColour[0], RoofColour[1], RoofColour[2]};
    Vertex v60{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*5, m_Position[2] + StartPos[2] + scale + scale/2, RoofColour[0], RoofColour[1], RoofColour[2]};


    // FLOOR
    Vertex v61{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], FloorColour[0], FloorColour[1], FloorColour[2]};
    Vertex v62{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], FloorColour[0], FloorColour[1], FloorColour[2]};
    Vertex v63{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, FloorColour[0], FloorColour[1], FloorColour[2]};

    Vertex v64{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], FloorColour[0], FloorColour[1], FloorColour[2]};
    Vertex v65{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, FloorColour[0], FloorColour[1], FloorColour[2]};
    Vertex v66{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, FloorColour[0], FloorColour[1], FloorColour[2]};


    // FOUNDATION
    // FRONT
    Vertex v67{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v68{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v69{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};

    Vertex v70{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v71{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v72{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};

    // WEST
    Vertex v73{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v74{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v75{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};

    Vertex v76{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v77{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v78{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};

    // BACK
    Vertex v79{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v80{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v81{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};

    Vertex v82{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v83{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v84{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};

    // EAST
    Vertex v85{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v86{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v87{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};

    Vertex v88{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v89{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2] + scale*3, FoundationColour[0], FoundationColour[1], FoundationColour[2]};
    Vertex v90{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] - scale*5, m_Position[2] + StartPos[2], FoundationColour[0], FoundationColour[1], FoundationColour[2]};



    HousePoints.push_back(v1);
    HousePoints.push_back(v2);
    HousePoints.push_back(v3);
    HousePoints.push_back(v4);
    HousePoints.push_back(v5);
    HousePoints.push_back(v6);

    HousePoints.push_back(v7);
    HousePoints.push_back(v8);
    HousePoints.push_back(v9);
    HousePoints.push_back(v10);
    HousePoints.push_back(v11);
    HousePoints.push_back(v12);

    HousePoints.push_back(v13);
    HousePoints.push_back(v14);
    HousePoints.push_back(v15);
    HousePoints.push_back(v16);
    HousePoints.push_back(v17);
    HousePoints.push_back(v18);

    HousePoints.push_back(v19);
    HousePoints.push_back(v20);
    HousePoints.push_back(v21);
    HousePoints.push_back(v22);
    HousePoints.push_back(v23);
    HousePoints.push_back(v24);

    HousePoints.push_back(v25);
    HousePoints.push_back(v26);
    HousePoints.push_back(v27);
    HousePoints.push_back(v28);
    HousePoints.push_back(v29);
    HousePoints.push_back(v30);

    HousePoints.push_back(v31);
    HousePoints.push_back(v32);
    HousePoints.push_back(v33);
    HousePoints.push_back(v34);
    HousePoints.push_back(v35);
    HousePoints.push_back(v36);

    HousePoints.push_back(v37);
    HousePoints.push_back(v38);
    HousePoints.push_back(v39);
    HousePoints.push_back(v40);
    HousePoints.push_back(v41);
    HousePoints.push_back(v42);

    HousePoints.push_back(v43);
    HousePoints.push_back(v44);
    HousePoints.push_back(v45);
    HousePoints.push_back(v46);
    HousePoints.push_back(v47);
    HousePoints.push_back(v48);

    HousePoints.push_back(v49);
    HousePoints.push_back(v50);
    HousePoints.push_back(v51);
    HousePoints.push_back(v52);
    HousePoints.push_back(v53);
    HousePoints.push_back(v54);

    HousePoints.push_back(v55);
    HousePoints.push_back(v56);
    HousePoints.push_back(v57);
    HousePoints.push_back(v58);
    HousePoints.push_back(v59);
    HousePoints.push_back(v60);

    HousePoints.push_back(v61);
    HousePoints.push_back(v62);
    HousePoints.push_back(v63);
    HousePoints.push_back(v64);
    HousePoints.push_back(v65);
    HousePoints.push_back(v66);

//    // FOUNDATIONS IN CASE NEEDED
    HousePoints.push_back(v67);
    HousePoints.push_back(v68);
    HousePoints.push_back(v69);
    HousePoints.push_back(v70);
    HousePoints.push_back(v71);
    HousePoints.push_back(v72);

    HousePoints.push_back(v73);
    HousePoints.push_back(v74);
    HousePoints.push_back(v75);
    HousePoints.push_back(v76);
    HousePoints.push_back(v77);
    HousePoints.push_back(v78);

    HousePoints.push_back(v79);
    HousePoints.push_back(v80);
    HousePoints.push_back(v81);
    HousePoints.push_back(v82);
    HousePoints.push_back(v83);
    HousePoints.push_back(v84);

    HousePoints.push_back(v85);
    HousePoints.push_back(v86);
    HousePoints.push_back(v87);
    HousePoints.push_back(v88);
    HousePoints.push_back(v89);
    HousePoints.push_back(v90);



    for (int i = 0; i < HousePoints.size(); i++)
    {
        mVertices.push_back(HousePoints[i]);
    }

    mMatrix.setToIdentity();
}

house::~house() {    }

void house::init(GLint matrixUniform) {
   mMatrixUniform = matrixUniform;

   initializeOpenGLFunctions();

   //Vertex Array Object - VAO
   glGenVertexArrays( 1, &mVAO );
   glBindVertexArray( mVAO );

   //Vertex Buffer Object to hold vertices - VBO
   glGenBuffers( 1, &mVBO );
   glBindBuffer( GL_ARRAY_BUFFER, mVBO );

   glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof( Vertex ), mVertices.data(), GL_STATIC_DRAW );

   // 1rst attribute buffer : vertices
   glBindBuffer(GL_ARRAY_BUFFER, mVBO);
   glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, sizeof(Vertex), (GLvoid*)0);
   glEnableVertexAttribArray(0);

   // 2nd attribute buffer : colors
   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof( Vertex ),  (GLvoid*)(3 * sizeof(GLfloat)) );
   glEnableVertexAttribArray(1);

   //enable the matrixUniform
   // mMatrixUniform = glGetUniformLocation( matrixUniform, "matrix" );

   glBindVertexArray(0);
}

void house::draw()
{
   glBindVertexArray( mVAO );
   glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
   glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
   // (0,0) (1,0) (2,0) (3,0)
}
