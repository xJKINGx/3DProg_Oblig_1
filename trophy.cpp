#include "trophy.h"

trophy::trophy() {

}

trophy::trophy(float scale) {
    // TROPHY CYLINDER
    // TOP
    Vertex v1{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v2{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v3{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v4{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v5{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v6{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // FRONT
    Vertex v7{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v8{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v9{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v10{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v11{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v12{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // EAST
    Vertex v13{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v14{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v15{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v16{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v17{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v18{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // BACK
    Vertex v19{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v20{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v21{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v22{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v23{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v24{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // WEST
    Vertex v25{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v26{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v27{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v28{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v29{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v30{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};


    // TROPHY BOWL
    // FRONT
    Vertex v37{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v38{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v39{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v40{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v41{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v42{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // EAST
    Vertex v43{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v44{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v45{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v46{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v47{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v48{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // BACK
    Vertex v49{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v50{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v51{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v52{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v53{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v54{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // WEST
    Vertex v55{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v56{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v57{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v58{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v59{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v60{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // BOTTOM
    Vertex v61{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v62{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v63{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v64{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v65{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v66{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // CORNERS
    // FRONT LEFT
    Vertex v67{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v68{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v69{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v70{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v71{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v72{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // FRONT RIGHT
    Vertex v73{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v74{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v75{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v76{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v77{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v78{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // BACK LEFT
    Vertex v79{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v80{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v81{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v82{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v83{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v84{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // BACK RIGHT
    Vertex v85{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v86{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v87{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v88{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v89{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v90{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};


    // TROPHY ROD
    // FRONT
    Vertex v91{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v92{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v93{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v94{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v95{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v96{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // WEST
    Vertex v97{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v98{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v99{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v100{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v101{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v102{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // BACK
    Vertex v103{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v104{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v105{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v106{m_Position[0] + StartPos[0] - scale/2 + scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v107{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v108{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // EAST
    Vertex v109{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v110{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v111{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v112{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v113{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 + scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v114{m_Position[0] + StartPos[0] - scale/2 - scale/10, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/2 - scale/10, TrophyColour[0], TrophyColour[1], TrophyColour[2]};


    // TROPHY PLATE
    // TOP
    Vertex v115{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v116{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v117{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v118{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v119{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v120{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // FRONT
    Vertex v121{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v122{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v123{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v124{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v125{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v126{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // WEST
    Vertex v127{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v128{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v129{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v130{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v131{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v132{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // BACK
    Vertex v133{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v134{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v135{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v136{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v137{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v138{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // EAST
    Vertex v139{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v140{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v141{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v142{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v143{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v144{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    // BOTTOM
    Vertex v145{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v146{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v147{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};

    Vertex v148{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v149{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};
    Vertex v150{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] - scale/5 - scale - scale/2 - scale/10, m_Position[2] + StartPos[2] + scale - scale/5, TrophyColour[0], TrophyColour[1], TrophyColour[2]};


    TrophyPoints.push_back(v1);
    TrophyPoints.push_back(v2);
    TrophyPoints.push_back(v3);
    TrophyPoints.push_back(v4);
    TrophyPoints.push_back(v5);
    TrophyPoints.push_back(v6);

    TrophyPoints.push_back(v7);
    TrophyPoints.push_back(v8);
    TrophyPoints.push_back(v9);
    TrophyPoints.push_back(v10);
    TrophyPoints.push_back(v11);
    TrophyPoints.push_back(v12);

    TrophyPoints.push_back(v13);
    TrophyPoints.push_back(v14);
    TrophyPoints.push_back(v15);
    TrophyPoints.push_back(v16);
    TrophyPoints.push_back(v17);
    TrophyPoints.push_back(v18);

    TrophyPoints.push_back(v19);
    TrophyPoints.push_back(v20);
    TrophyPoints.push_back(v21);
    TrophyPoints.push_back(v22);
    TrophyPoints.push_back(v23);
    TrophyPoints.push_back(v24);

    TrophyPoints.push_back(v25);
    TrophyPoints.push_back(v26);
    TrophyPoints.push_back(v27);
    TrophyPoints.push_back(v28);
    TrophyPoints.push_back(v29);
    TrophyPoints.push_back(v30);

    TrophyPoints.push_back(v37);
    TrophyPoints.push_back(v38);
    TrophyPoints.push_back(v39);
    TrophyPoints.push_back(v40);
    TrophyPoints.push_back(v41);
    TrophyPoints.push_back(v42);

    TrophyPoints.push_back(v43);
    TrophyPoints.push_back(v44);
    TrophyPoints.push_back(v45);
    TrophyPoints.push_back(v46);
    TrophyPoints.push_back(v47);
    TrophyPoints.push_back(v48);

    TrophyPoints.push_back(v49);
    TrophyPoints.push_back(v50);
    TrophyPoints.push_back(v51);
    TrophyPoints.push_back(v52);
    TrophyPoints.push_back(v53);
    TrophyPoints.push_back(v54);

    TrophyPoints.push_back(v55);
    TrophyPoints.push_back(v56);
    TrophyPoints.push_back(v57);
    TrophyPoints.push_back(v58);
    TrophyPoints.push_back(v59);
    TrophyPoints.push_back(v60);

    TrophyPoints.push_back(v61);
    TrophyPoints.push_back(v62);
    TrophyPoints.push_back(v63);
    TrophyPoints.push_back(v64);
    TrophyPoints.push_back(v65);
    TrophyPoints.push_back(v66);

    TrophyPoints.push_back(v67);
    TrophyPoints.push_back(v68);
    TrophyPoints.push_back(v69);
    TrophyPoints.push_back(v70);
    TrophyPoints.push_back(v71);
    TrophyPoints.push_back(v72);

    TrophyPoints.push_back(v73);
    TrophyPoints.push_back(v74);
    TrophyPoints.push_back(v75);
    TrophyPoints.push_back(v76);
    TrophyPoints.push_back(v77);
    TrophyPoints.push_back(v78);

    TrophyPoints.push_back(v79);
    TrophyPoints.push_back(v80);
    TrophyPoints.push_back(v81);
    TrophyPoints.push_back(v82);
    TrophyPoints.push_back(v83);
    TrophyPoints.push_back(v84);

    TrophyPoints.push_back(v85);
    TrophyPoints.push_back(v86);
    TrophyPoints.push_back(v87);
    TrophyPoints.push_back(v88);
    TrophyPoints.push_back(v89);
    TrophyPoints.push_back(v90);

    TrophyPoints.push_back(v91);
    TrophyPoints.push_back(v92);
    TrophyPoints.push_back(v93);
    TrophyPoints.push_back(v94);
    TrophyPoints.push_back(v95);
    TrophyPoints.push_back(v96);

    TrophyPoints.push_back(v97);
    TrophyPoints.push_back(v98);
    TrophyPoints.push_back(v99);
    TrophyPoints.push_back(v100);
    TrophyPoints.push_back(v101);
    TrophyPoints.push_back(v102);

    TrophyPoints.push_back(v103);
    TrophyPoints.push_back(v104);
    TrophyPoints.push_back(v105);
    TrophyPoints.push_back(v106);
    TrophyPoints.push_back(v107);
    TrophyPoints.push_back(v108);

    TrophyPoints.push_back(v109);
    TrophyPoints.push_back(v110);
    TrophyPoints.push_back(v111);
    TrophyPoints.push_back(v112);
    TrophyPoints.push_back(v113);
    TrophyPoints.push_back(v114);

    TrophyPoints.push_back(v115);
    TrophyPoints.push_back(v116);
    TrophyPoints.push_back(v117);
    TrophyPoints.push_back(v118);
    TrophyPoints.push_back(v119);
    TrophyPoints.push_back(v120);

    TrophyPoints.push_back(v121);
    TrophyPoints.push_back(v122);
    TrophyPoints.push_back(v123);
    TrophyPoints.push_back(v124);
    TrophyPoints.push_back(v125);
    TrophyPoints.push_back(v126);

    TrophyPoints.push_back(v127);
    TrophyPoints.push_back(v128);
    TrophyPoints.push_back(v129);
    TrophyPoints.push_back(v130);
    TrophyPoints.push_back(v131);
    TrophyPoints.push_back(v132);

    TrophyPoints.push_back(v133);
    TrophyPoints.push_back(v134);
    TrophyPoints.push_back(v135);
    TrophyPoints.push_back(v136);
    TrophyPoints.push_back(v137);
    TrophyPoints.push_back(v138);

    TrophyPoints.push_back(v139);
    TrophyPoints.push_back(v140);
    TrophyPoints.push_back(v141);
    TrophyPoints.push_back(v142);
    TrophyPoints.push_back(v143);
    TrophyPoints.push_back(v144);

    TrophyPoints.push_back(v145);
    TrophyPoints.push_back(v146);
    TrophyPoints.push_back(v147);
    TrophyPoints.push_back(v148);
    TrophyPoints.push_back(v149);
    TrophyPoints.push_back(v150);





    for (int i = 0; i < TrophyPoints.size(); i++)
    {
        mVertices.push_back(TrophyPoints[i]);
    }

    mMatrix.setToIdentity();
}

trophy::~trophy() {    }

void trophy::init(GLint matrixUniform) {
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

void trophy::draw()
{
   glBindVertexArray( mVAO );
   glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
   glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
   // (0,0) (1,0) (2,0) (3,0)
}
