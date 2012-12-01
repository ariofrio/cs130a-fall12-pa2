> ./bst
> insert 20
< Element inserted
> insert 10
< Element inserted
> insert 2
< Element inserted
> access 2
< Element accessed
> print
< 20 10 2
< 2 10 20
> insert 15
< Element inserted
> insert 18
< Element inserted
> insert 12
< Element inserted
> access 15
< Element accessed
> print
< 20 10 2 15 12 18
< 2 10 12 15 18 20
> delete 10
< Element deleted
> print
< 20 12 2 15 18
< 2 12 15 18 20
> delete 18
< Element deleted
> print
< 20 12 2 15
< 2 12 15 20
> delete 20
< Element deleted
> print
< 12 2 15
< 2 12 15
> insert 7
< Element inserted
> print
< 12 2 7 15
< 2 7 12 15
