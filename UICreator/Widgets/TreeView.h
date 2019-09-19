#pragma once
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "TreeNode.h"


class TreeView
{
	typedef void(*tv_callback)(TreeNode *nodeSelected);

public:
	TreeView(unsigned int x,
		unsigned int y,
		unsigned int width,
		unsigned int height,
		std::string title,
		bool inWindow = false,
		lv_obj_t* parent = nullptr);
	~TreeView();

	unsigned int AddNode(std::string name, lv_obj_t* object,
		unsigned int parentID = 0,
		bool protect = false);
	lv_obj_t *GetTreeViewUI();
	TreeNode *GetSelectedNode();
	
	void AddSelectCallback(tv_callback cb);
	void AddDeleteCallback(tv_callback cb);

	
private:
	int x, y, width, height, yOffset, curID=0;
	std::string title;
	lv_obj_t *tvContainer;
	TreeNode *selectedNode=nullptr;
	
	lv_obj_t *window, *deleteButton, *treeContainer,
		*moveUpButton, *moveDownButton, *copyButton, *pasteButton;

	std::vector<TreeNode*> topLevelNodes;
	
	void createTreeViewContainer(bool inWin, lv_obj_t *parent);
	void createUIObjects(TreeNode *node);
	
	TreeNode *getNode(TreeNode* node, unsigned int nodeID);

	std::vector<TreeNode*> getAllNodes();
	std::vector<TreeNode*> getAllNodes(TreeNode *node);
	
	// Callbacks
	static void deleteButtonCB(lv_obj_t * obj, lv_event_t ev);
	static void expandButtonCB(lv_obj_t * obj, lv_event_t ev);
	static void labelButtonCB(lv_obj_t * obj, lv_event_t ev);
	static void moveUpButtonCB(lv_obj_t * obj, lv_event_t ev);
	static void copyButtonCB(lv_obj_t * obj, lv_event_t ev);
	static void pasteButtonCB(lv_obj_t * obj, lv_event_t ev);
	static void moveDownButtonCB(lv_obj_t * obj, lv_event_t ev);

	tv_callback selectCallbackFunc = nullptr;
	tv_callback deleteCallbackFunc = nullptr;
};