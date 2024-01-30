using System;
using System.Collections;
using System.Collections.Generic;
using _253504_zhgutov_Lab6.Interfaces;
using _253504_zhgutov_Lab6.Exceptions;

namespace _253504_zhgutov_Lab6.Collections
{
    public class MyCustomCollection<T> : ICustomCollection<T>,IEnumerable<T>
    {
        private class Node
        {
            public T Data { get; set; }
            
            public Node? Next { get; set; }

            public Node(T data)
            {
                this.Data = data;
                this.Next = null;
            }
        }

        private Node head;
        private Node current;
        private int count;  
        
        public T this[int index]
        {
            get
            {
                if (index >= 0 && index < count)
                {
                    Node currentNode = head;
                    for (int i = 0; i < index; i++)
                    {
                        currentNode = currentNode.Next;
                    }
                    return currentNode.Data;
                }
                throw new IndexOutOfRangeException("Index is out of range");
            }
            set
            {
                if (index >= 0 && index < count)
                {
                    Node currentNode = head;
                    for (int i = 0; i < index; i++)
                    {
                        currentNode = currentNode.Next;
                    }
                    currentNode.Data = value;
                }
                else
                {
                    throw new IndexOutOfRangeException("Index is out of range");
                }
            }
        }

        public void Reset()
        {
            this.current = head;
        }

        public void Next()
        {
            if (current != null)
            {
                this.current = current.Next;
            }
        }

        public T Current()
        {
            if (current != null)
            {
                return current.Data;
            }
            throw new InvalidOperationException("Cursor is not positioned on a valid element");
        }

        public int Count
        {
            get
            {
                return count;
            }
        }

        public void Add(T item)
        {
            if (count >= int.MaxValue)
            {
                throw new InvalidOperationException("Collection is full.");
            }
            Node newNode = new Node(item);
            if (head == null)
            {
                this.head = newNode;
                this.current = head;
            }
            else
            {
                Node currentNode = head;
                while (currentNode.Next != null)
                {
                    currentNode = currentNode.Next;
                }
                currentNode.Next = newNode;
            }
            count++;
        }

        public void Remove(T item)
        {
            if (head == null)
            {
                throw new InvalidOperationException("Item doesn't exist in this collection.");
            }
            if (head.Data.Equals(item))
            {
                this.head = head.Next;
                count--;
                return;
            }
            Node currentNode = head;
            while (currentNode.Next != null)
            {
                if (currentNode.Next.Data.Equals(item))
                {
                    currentNode.Next = currentNode.Next.Next;
                    count--;
                    return;
                }
                currentNode = currentNode.Next;
            }
            throw new ItemNotFoundException("Item doesn't exist in this collection.");
        }

        public T RemoveCurrent()
        {
            if (current != null)
            {
                T data = current.Data;
                Remove(data);
                return data;
            }
            throw new InvalidOperationException("Cursor is not positioned on a valid element");
        }

        public IEnumerator<T> GetEnumerator()
        {
            Node currentNode = head;
            while (currentNode != null)
            {
                yield return currentNode.Data;
                currentNode = currentNode.Next;
            }
        }
        
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}