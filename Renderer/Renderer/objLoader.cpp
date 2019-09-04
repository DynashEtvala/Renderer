#include "objLoader.h"
#define TINYOBJLOADER_IMPLEMENTATION
#include "tinyobjloader/tiny_obj_loader.h"
#include "render.h"
#include <algorithm>

vertex * loadOBJ(std::string fileName)
{
	//tinyobj::attrib_t attrib;
	//std::vector<tinyobj::shape_t> shapes;
	//std::vector<tinyobj::material_t> materials;

	//std::string warn;
	//std::string err;

	//tinyobj::LoadObj(&attrib, &shapes, &materials, &err, fileName.c_str());
	//const int n = attrib.vertices.size();
	//
	//std::vector<vertex> vertstemp;
	//std::vector<unsigned int> indexestemp;

	//// Loop over shapes
	//for (size_t s = 0; s < shapes.size(); s++)
	//{
	//	// Loop over faces(polygon)
	//	size_t index_offset = 0;
	//	for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++)
	//	{
	//		int fv = shapes[s].mesh.num_face_vertices[f];

	//		// Loop over vertices in the face.
	//		for (size_t v = 0; v < fv; v++)
	//		{
	//			// access to vertex
	//			tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
	//			tinyobj::real_t vx = attrib.vertices[3 * idx.vertex_index + 0];
	//			tinyobj::real_t vy = attrib.vertices[3 * idx.vertex_index + 1];
	//			tinyobj::real_t vz = attrib.vertices[3 * idx.vertex_index + 2];
	//			tinyobj::real_t nx = attrib.normals[3 * idx.normal_index + 0];
	//			tinyobj::real_t ny = attrib.normals[3 * idx.normal_index + 1];
	//			tinyobj::real_t nz = attrib.normals[3 * idx.normal_index + 2];
	//			tinyobj::real_t tx = attrib.texcoords[2 * idx.texcoord_index + 0];
	//			tinyobj::real_t ty = attrib.texcoords[2 * idx.texcoord_index + 1];
	//			vertex tempVert = { {vx, vy, vz, 1}, { nx, ny, nz, 0 }, {tx, ty}, { 1, 1, 1, 1 } };
	//			vertstemp.push_back(tempVert);
	//			indexestemp.push_back();

	//		}
	//		index_offset += fv;

	//		// per-face material
	//		shapes[s].mesh.material_ids[f];
	//	}
	//}

	return nullptr;
}
