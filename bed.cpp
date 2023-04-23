#include "bed.h"

bed::bed()
{

}

bed::bed(float scale, QVector3D start)
{
    m_Position = start;
    // MAIN
    // FRONT
    Vertex v1{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v2{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v3{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};

    Vertex v4{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v5{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v6{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};

    // WEST
    Vertex v7{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v8{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v9{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};

    Vertex v10{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v11{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};
    Vertex v12{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};

    // BACK
    Vertex v13{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};
    Vertex v14{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};
    Vertex v15{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};

    Vertex v16{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};
    Vertex v17{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};
    Vertex v18{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};

    // EAST
    Vertex v19{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v20{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v21{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};

    Vertex v22{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v23{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};
    Vertex v24{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};

    // BOTTOM
    Vertex v25{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v26{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v27{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};

    Vertex v28{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};
    Vertex v29{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};
    Vertex v30{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};

    // TOP
    Vertex v31{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v32{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};
    Vertex v33{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};

    Vertex v34{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};
    Vertex v35{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2, BedColour[0], BedColour[1], BedColour[2]};
    Vertex v36{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2], BedColour[0], BedColour[1], BedColour[2]};


    // MATRESS
    // FRONT
    Vertex v37{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v38{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v39{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    Vertex v40{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v41{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v42{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    // WEST
    Vertex v43{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v44{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v45{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    Vertex v46{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v47{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v48{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    // BACK
    Vertex v49{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v50{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v51{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    Vertex v52{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v53{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v54{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    // EAST
    Vertex v55{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v56{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v57{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    Vertex v58{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v59{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v60{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2, m_Position[2] + StartPos[2] + scale*2 - scale/10, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    // TOP
    Vertex v61{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale/12, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v62{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale/12, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v63{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/12, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    Vertex v64{m_Position[0] + StartPos[0] - scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/12, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v65{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale/12, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v66{m_Position[0] + StartPos[0] - scale + scale/12, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/12, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};


    // PILLOW
    // FRONT
    Vertex v67{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v68{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v69{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    Vertex v70{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v71{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v72{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    // WEST
    Vertex v73{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v74{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v75{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    Vertex v76{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v77{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v78{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    // BACK
    Vertex v79{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v80{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v81{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    Vertex v82{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v83{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v84{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    // EAST
    Vertex v85{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v86{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v87{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    Vertex v88{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v89{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v90{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    // TOP
    Vertex v91{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v92{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v93{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};

    Vertex v94{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/2, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v95{m_Position[0] + StartPos[0] - scale + scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};
    Vertex v96{m_Position[0] + StartPos[0] - scale/5, m_Position[1] + StartPos[1] + scale/2 + scale/5 + scale/10, m_Position[2] + StartPos[2] + scale*2 - scale/5, MatressAndPillowColour[0], MatressAndPillowColour[1], MatressAndPillowColour[2]};



    BedPoints.push_back(v1);
    BedPoints.push_back(v2);
    BedPoints.push_back(v3);
    BedPoints.push_back(v4);
    BedPoints.push_back(v5);
    BedPoints.push_back(v6);

    BedPoints.push_back(v7);
    BedPoints.push_back(v8);
    BedPoints.push_back(v9);
    BedPoints.push_back(v10);
    BedPoints.push_back(v11);
    BedPoints.push_back(v12);

    BedPoints.push_back(v13);
    BedPoints.push_back(v14);
    BedPoints.push_back(v15);
    BedPoints.push_back(v16);
    BedPoints.push_back(v17);
    BedPoints.push_back(v18);

    BedPoints.push_back(v19);
    BedPoints.push_back(v20);
    BedPoints.push_back(v21);
    BedPoints.push_back(v22);
    BedPoints.push_back(v23);
    BedPoints.push_back(v24);

    BedPoints.push_back(v25);
    BedPoints.push_back(v26);
    BedPoints.push_back(v27);
    BedPoints.push_back(v28);
    BedPoints.push_back(v29);
    BedPoints.push_back(v30);

    BedPoints.push_back(v31);
    BedPoints.push_back(v32);
    BedPoints.push_back(v33);
    BedPoints.push_back(v34);
    BedPoints.push_back(v35);
    BedPoints.push_back(v36);

    BedPoints.push_back(v37);
    BedPoints.push_back(v38);
    BedPoints.push_back(v39);
    BedPoints.push_back(v40);
    BedPoints.push_back(v41);
    BedPoints.push_back(v42);

    BedPoints.push_back(v43);
    BedPoints.push_back(v44);
    BedPoints.push_back(v45);
    BedPoints.push_back(v46);
    BedPoints.push_back(v47);
    BedPoints.push_back(v48);

    BedPoints.push_back(v49);
    BedPoints.push_back(v50);
    BedPoints.push_back(v51);
    BedPoints.push_back(v52);
    BedPoints.push_back(v53);
    BedPoints.push_back(v54);

    BedPoints.push_back(v55);
    BedPoints.push_back(v56);
    BedPoints.push_back(v57);
    BedPoints.push_back(v58);
    BedPoints.push_back(v59);
    BedPoints.push_back(v60);

    BedPoints.push_back(v61);
    BedPoints.push_back(v62);
    BedPoints.push_back(v63);
    BedPoints.push_back(v64);
    BedPoints.push_back(v65);
    BedPoints.push_back(v66);

    BedPoints.push_back(v67);
    BedPoints.push_back(v68);
    BedPoints.push_back(v69);
    BedPoints.push_back(v70);
    BedPoints.push_back(v71);
    BedPoints.push_back(v72);

    BedPoints.push_back(v73);
    BedPoints.push_back(v74);
    BedPoints.push_back(v75);
    BedPoints.push_back(v76);
    BedPoints.push_back(v77);
    BedPoints.push_back(v78);

    BedPoints.push_back(v79);
    BedPoints.push_back(v80);
    BedPoints.push_back(v81);
    BedPoints.push_back(v82);
    BedPoints.push_back(v83);
    BedPoints.push_back(v84);

    BedPoints.push_back(v85);
    BedPoints.push_back(v86);
    BedPoints.push_back(v87);
    BedPoints.push_back(v88);
    BedPoints.push_back(v89);
    BedPoints.push_back(v90);

    BedPoints.push_back(v91);
    BedPoints.push_back(v92);
    BedPoints.push_back(v93);
    BedPoints.push_back(v94);
    BedPoints.push_back(v95);
    BedPoints.push_back(v96);



    for (int i = 0; i < BedPoints.size(); i++)
    {
        mVertices.push_back(BedPoints[i]);
    }

    mMatrix.setToIdentity();
}

bed::~bed()
{

}

void bed::init(GLint matrixUniform) {
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

   glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE,  sizeof(Vertex),  (GLvoid*)(8 * sizeof(GLfloat)) );
   glEnableVertexAttribArray(3);

   glBindVertexArray(0);
}

void bed::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
    // (0,0) (1,0) (2,0) (3,0)
}
