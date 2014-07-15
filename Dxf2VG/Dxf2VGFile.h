#ifndef __DXF2VGFILE_H__
#define __DXF2VGFILE_H__

#include "dl_creationadapter.h"
#include "mgshapedoc.h"

class Dxf2VGFile : public DL_CreationAdapter
{
public:
	Dxf2VGFile();
	~Dxf2VGFile();

	virtual void addLayer(const DL_LayerData& data);
	virtual void addPoint(const DL_PointData& data);
	virtual void addLine(const DL_LineData& data);
	virtual void addArc(const DL_ArcData& data);
	virtual void addCircle(const DL_CircleData& data);
	virtual void addPolyline(const DL_PolylineData& data);
	virtual void addVertex(const DL_VertexData& data);
	virtual void add3dFace(const DL_3dFaceData& data);

	void printAttributes();

	void SaveFile(std::string strvg);

private:
	MgShapeDoc *m_mgDoc;
	int m_nLayerCount;
	int m_nVertex;
	MgShape *m_pShape;
};
#endif