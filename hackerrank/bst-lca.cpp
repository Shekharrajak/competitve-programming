int bst_lca(node* cur_root,int v1,int v3)
{
if(!cur_root)
		return -1;//error
	if(v1<cur_root->v && v2<cur_root->v)
		return bst_lca(cur_root->left,v1,v2);
	else if(v1>cur_root->v && v2>cur_root->v)
		return bst_lca(cur_root->right,v1,v2);
	else return cur_root->v;
}
