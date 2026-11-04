Parameter A B C D:Prop.

Lemma example1: (A->B) -> (B->C) -> (A->C).
Proof.
intro H.
intro H0.
intro H1.
apply H0.
apply H.
exact H1.
Qed.

Lemma q1: A->A.
Proof.
intro H.
exact H.
Qed.

Lemma q2: A->(B->A).
Proof.
intro H. 
intro H0.
exact H.
Qed.

Lemma q3: (A->B->C)->B->A->C.
Proof.
intro H.
intro H0. 
intro H1.
apply H.
exact H1.
exact H0.
Qed.

Lemma q4: (A->A->B)->A->B.
Proof.
intro H.
intro H0.
apply H.
exact H0.
apply H0.
Qed.

Lemma q5: (A->B)->A->A->B.
Proof.
intro H.
intro H0.
exact H.
Qed.

Lemma q6: (A->B)->(A->C)->(B->C->D)->A->D.
Proof.
intro H.
intro H0.
intro H1.
intro H2.
apply H1.
apply H.
exact H2.
apply H0.
apply H2.
Qed.

Lemma q7: ((((A->B)->A)->A)->B)->B.
Proof. 
intro H.
apply H.
intro H0.
apply H0.
intro H1.
apply H.
intro H2.
apply H1.
Qed.
