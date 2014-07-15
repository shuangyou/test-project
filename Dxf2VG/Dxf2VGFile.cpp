#include "stdafx.h"
#include "Dxf2VGFile.h"

#include "mgbasicsp.h"
#include "mgshape.h"
#include "mgshapeT.h"
#include "mglayer.h"

#include "MgJsonStorage.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Dxf2VGFile::Dxf2VGFile()
{
	m_nLayerCount = 0;
	m_nVertex = 0;
	m_pShape = NULL;
	m_mgDoc = MgShapeDoc::createDoc();
}

Dxf2VGFile::~Dxf2VGFile()
{
	if (m_mgDoc)
	{
		m_mgDoc->release();
		m_mgDoc = NULL;
	}
}

void Dxf2VGFile::addLayer(const DL_LayerData& data)
{
	if (m_mgDoc->switchLayer(m_nLayerCount))
	{
		//MgLayer *pLayer = m_mgDoc.getCurrentLayer();
		//pLayer->set
		++m_nLayerCount;
	}
	
}

void Dxf2VGFile::addPoint(const DL_PointData& data)
{
	
}

void Dxf2VGFile::addLine(const DL_LineData& data)
{
	MgShapeT<MgLine> mgline;

	Point2d pt1(data.x1,data.x2);
	Point2d pt2(data.x2,data.y2);
	mgline.shape()->setPoint(0,pt1);
	mgline.shape()->setPoint(1,pt2);

	MgLayer *pLayer = m_mgDoc->getCurrentLayer();
	pLayer->addShape(mgline);

	std::cout<<"Add line"<<std::endl;

}

void Dxf2VGFile::addArc(const DL_ArcData& data)
{
	
}

void Dxf2VGFile::addCircle(const DL_CircleData& data)
{

}

void Dxf2VGFile::addPolyline(const DL_PolylineData& data)
{
	MgShapeT<MgLines> mglines;
	MgLayer *pLayer = m_mgDoc->getCurrentLayer();
	m_pShape = pLayer->addShape(mglines);

	std::cout<<"Add Polyline"<<std::endl;
}

void Dxf2VGFile::addVertex(const DL_VertexData& data)
{
	Point2d pt(data.x,data.y);
	if (m_mgDoc->getLastShape()->shapec()->getType() == 15)
	{
		((MgLines*)m_pShape->shape())->addPoint(pt);
	}
}

void Dxf2VGFile::add3dFace(const DL_3dFaceData& data)
{

}

void Dxf2VGFile::SaveFile(std::string strvg)
{
	FILE *fp = mgopenfile(strvg.c_str(), "wt");
	MgJsonStorage s;
	m_mgDoc->save(s.storageForWrite(),-1);
	s.save(fp);
	if (fp)
	{
		fclose(fp);
	}
	
}