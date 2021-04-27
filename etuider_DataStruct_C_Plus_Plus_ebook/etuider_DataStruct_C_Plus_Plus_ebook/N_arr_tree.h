#pragma once
#include "stdafx.h"

struct n_array_node
{
	string name;
	bool is_dir;
	vector<n_array_node*> children;
};

struct file_system
{
	using node = n_array_node;
	using node_ptr = node*;

private:
	node_ptr root; 
	node_ptr cwd;

public:
	file_system()
	{
		root = new node{ "/", true, {} };
		cwd = root; //ó������ ��Ʈ�� ���� ���丮�� ����
	}

	node_ptr find(const string& path)
	{
		if (path[0] == '/') //���� ���
		{
			return find_impl(root, path.substr(1));
		}
		else //�����
		{
			return find_impl(cwd, path);
		}
	}
private:
	node_ptr find_impl(node_ptr directory, const string& path)
	{
		if (path.empty())
			return directory;
		auto sep = path.find('/');
		string current_path = sep == string::npos ? path : path.substr(0, sep);
		string rest_path = sep == string::npos ? "" : path.substr(sep + 1);
		auto found = find_if(directory->children.begin(), directory->children.end(),
			[&](const node_ptr child) {
				return child->name == current_path;
			});
		if (found != directory->children.end())
		{
			return find_impl(*found, rest_path);
		}
		return NULL;
	}
public:
	bool add(string& path, bool is_dir)
	{
		if (path[0] == '/')
		{
			return add_impl(root, path.substr(1), is_dir);
		}
		else
		{
			return add_impl(cwd, path, is_dir);
		}
	}
private:
	bool add_impl(node_ptr directory, string& path, bool is_dir)
	{
		if (!directory->is_dir)
		{
			cout << directory->name << "��(��) �����Դϴ�." << endl;
			return false;
		}
		auto sep = path.find('/');

		//path�� '/'�� ���� ���
		if (sep == string::npos)
		{
			auto found = find_if(directory->children.begin(), directory->children.end(), 
				[&](const node_ptr child) 
				{return child->name == path;});

			if (found != directory->children.end())
			{
				cout << directory->name << "�� �̹� " << path << " �̸��� ����/���丮�� �ֽ��ϴ�." << endl;
				return false;
			}
			directory->children.push_back(new node{ path, is_dir, {} });
			return true;
		}

		//path�� '/'�� �ִ� ���, ��, ���丮 �̸��� �����ϰ� �ִ� ���.
		string next_dir = path.substr(0, sep);
		auto found = find_if(directory->children.begin(), directory->children.end(),
			[&](const node_ptr child) {return child->name == next_dir && child->is_dir; });

		if (found != directory->children.end())
		{
			return add_impl(*found, path.substr(sep + 1), is_dir);
		}

		//path�� ���丮 �̸��� ���ԵǾ� ������, �ش� ���丮�� ���� ���.
		cout << directory->name << "�� " << next_dir << " �̸��� ���丮�� �����ϴ�." << endl;
		return false;
	}
public:
	bool change_dir(const string& path)
	{
		auto found = find(path);
		if (found && found->is_dir)
		{
			cwd = found;
			cout << "���� ���丮�� " << cwd->name << "�� �̵��մϴ�." << endl;
			return true;
		}

		cout << path << " ��θ� ã�� �� �����ϴ�." << endl;
		return false;
	}

	void show_path(const string& path)
	{
		auto found = find(path);
		if (!found)
		{
			cout << path << " ��ΰ� �������� �ʽ��ϴ�." << endl;
			return;
		}

		if (found->is_dir)
		{
			for (auto child : found->children)
			{
				cout << (child->is_dir ? "d " : "- ") << child->name << endl;
			}
		}
		else
		{
			cout << "- " << found->name << endl;
		}
	}
};